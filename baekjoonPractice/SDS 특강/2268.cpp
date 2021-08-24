#include <iostream>
#include <algorithm>
#define ll long long
#define mid (s+e)/2
using namespace std;
ll n, m, tree[4000001];
ll query(ll root, ll s, ll e, ll l, ll r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[root];
	return query(root * 2, s, mid, l, r) + query(root * 2 + 1, mid + 1, e, l, r);
}
ll update(ll root, ll s, ll e, ll idx, ll val) {
	if (idx < s || e < idx) return tree[root];
	if (idx == s && e == idx) return tree[root] = val;
	return tree[root] = update(root * 2, s, mid, idx, val) + update(root * 2 + 1, mid + 1, e, idx, val);

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 0) cout << query(1, 1, n, min(b, c), max(b, c)) << '\n';
		else update(1, 1, n, b, c);
	}
}