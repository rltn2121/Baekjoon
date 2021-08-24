#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mid (s+e)/2
using namespace std;
int n, m, arr[100001], tree[400001];

int init(int root, int s, int e) {
	if (s == e) return tree[root] = arr[s];
	return tree[root] = min(init(root * 2, s, mid), init(root * 2 + 1, mid + 1, e));
}

int query(int root, int s, int e, int l, int r) {
	if (r < s || e < l) return 1e9;
	if (l <= s && e <= r) return tree[root];
	return min(query(root * 2, s, mid, l, r), query(root * 2 + 1, mid + 1, e, l, r));
}

int update(int root, int s, int e, int idx, int val) {
	if (idx < s || e < idx) return tree[root];
	if (s == e) return tree[root] = val;
	return tree[root] = min(update(root * 2, s, mid, idx, val), update(root * 2 + 1, mid + 1, e, idx, val));
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
		else cout << query(1, 1, n, b, c) << '\n';
	}
}