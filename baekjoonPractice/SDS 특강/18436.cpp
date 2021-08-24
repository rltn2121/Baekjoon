#include <iostream>
#define mid (s+e)/2
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
struct Node {
	int odd, even;
};
int n, m,arr[100001];
Node tree[400001];

Node init(int root, int s, int e) {
	if (s == e) {
		if (arr[s] % 2) tree[root] = { 1, 0 };
		else tree[root] = { 0,1 };
	}
//	if (s == e) tree[root] = { arr[s], arr[s] };
	else {
		Node ll = init(root * 2, s, mid);
		Node rr = init(root * 2 + 1, mid + 1, e);
		tree[root] = { ll.odd + rr.odd, ll.even + rr.even };
	}
	return tree[root];
}

Node update(int root, int s, int e, int idx, int val) {
	if (idx < s || e < idx) return tree[root];
	if (s == e) {
		if (val % 2) tree[root] = { 1,0 };
		else tree[root] = { 0,1 };
	}
	else {
		Node ll = update(root * 2, s, mid, idx, val);
		Node rr = update(root * 2 + 1, mid + 1, e, idx, val);
		tree[root] = { ll.odd + rr.odd, ll.even + rr.even };
	}
	return tree[root];
}

Node query(int root, int s, int e, int l, int r) {
	if (r < s || e < l) return { 0,0 };
	if (l <= s && e <= r) return tree[root];
	Node ll = query(root * 2, s, mid, l, r);
	Node rr = query(root * 2 + 1, mid + 1, e, l, r);
	return { ll.odd + rr.odd, ll.even + rr.even };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n)
		cin >> arr[i];

	init(1, 1, n);
	cin >> m;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else if (a == 2) cout << query(1, 1, n, b, c).even << '\n';
		else cout << query(1, 1, n, b, c).odd << '\n';
	}
}