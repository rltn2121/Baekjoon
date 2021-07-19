#include <iostream>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mid (s+e)/2
using namespace std;
struct Node {
	int idx, val;
};
int n, m;
Node arr[100001], tree[400001];

Node init(int root, int s, int e) {
	if (s == e) return tree[root] = arr[s];
	Node ll = init(root * 2, s, mid);
	Node rr = init(root * 2 + 1, mid + 1, e);

	if (ll.val == rr.val) {
		if (ll.idx < rr.idx) tree[root] = ll;
		else tree[root] = rr;
	}
	else if (ll.val < rr.val) tree[root] = ll;
	else tree[root] = rr;
	return tree[root];
}

Node update(int root, int s, int e, int idx, int val) {
	if (idx < s || e < idx) return tree[root];
	if (s == e) return tree[root] = { tree[root].idx, val };

	Node ll = update(root * 2, s, mid, idx, val);
	Node rr = update(root * 2 + 1, mid + 1, e, idx, val);
	if (ll.val == rr.val) {
		if (ll.idx < rr.idx) tree[root] = ll;
		else tree[root] = rr;
	}
	else if (ll.val < rr.val) tree[root] = ll;
	else tree[root] = rr;
	return tree[root];
}

Node query(int root, int s, int e, int l, int r) {
	if (r < s || e < l) return { (int)1e9, (int)1e9 };
	if (l <= s && e <= r) return tree[root];

	Node ll = query(root * 2, s, mid, l, r);
	Node rr = query(root * 2 + 1, mid + 1, e, l, r);
	if (ll.val == rr.val) {
		if (ll.idx < rr.idx) return ll;
		else return rr;
	}
	else if (ll.val < rr.val) return ll;
	else return rr;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		int x;
		cin >> x;
		arr[i] = { i,x };
	}
	init(1, 1, n);
	cin >> m;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else cout << query(1, 1, n, b, c).idx << '\n';
	}
}