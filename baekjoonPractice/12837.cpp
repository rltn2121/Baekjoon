#include <iostream>
#define ll long long
#define mid (s+e)/2
#define rep(i,n) for(int i=1;i<=n;i++)
int n, q;
ll tree[4000001];
using namespace std;
ll query(ll root, ll s, ll e, ll l, ll r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[root];
	return query(root * 2, s, mid, l, r) + query(root * 2 + 1, mid + 1, e, l, r);
}
ll update(ll root, ll s, ll e, ll l, ll r) {
	if (l < s || e < l) return tree[root];
	if (s==e) return tree[root] += r;
	return tree[root] = update(root * 2, s, mid, l, r) + update(root * 2 + 1, mid + 1, e, l, r);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	rep(i, q) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else cout << query(1, 1, n, b, c) << '\n';
	}
}