#include <iostream>
#include <algorithm>
#define ll long long
#define mid (s+e)/2
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, q;
ll arr[100001], tree[100001 * 4 + 1];
ll init(int root, int s, int e) {
	if (s == e) return tree[root] = arr[s];
	return tree[root] = init(root * 2, s, mid) + init(root * 2 + 1, mid + 1, e);
}

ll update(int root, int s, int e, int idx, int num) {
	if (idx < s || e < idx) return tree[root];
	if (s == e) return tree[root] = num;
	return tree[root] = update(root * 2, s, mid, idx, num) + update(root * 2 + 1, mid + 1, e, idx, num);
}

ll query(int root, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[root];
	return query(root * 2, s, mid, l, r) + query(root * 2 + 1, mid + 1, e, l, r);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	rep(i, n)
		cin >> arr[i];
	init(1, 1, n);
	rep(i, q) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		cout << query(1, 1, n, min(x,y), max(x,y)) << '\n';
		update(1, 1, n, a, b);
	}
}