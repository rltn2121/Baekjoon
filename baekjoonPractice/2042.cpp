#include <iostream>
#define ll long long
#define rep(i,n) for(ll i=1;i<=n;i++)
using namespace std;
ll n, m, k, tree[1000000*4+1], arr[1000001], a,b,c;

ll init(ll root, ll s, ll e) {
	if (s == e) return tree[root] = arr[s];
	ll mid = (s + e) / 2;
	return tree[root] = init(root * 2, s, mid) + init(root * 2 + 1, mid + 1, e);
}

ll query(ll root, ll s, ll e, ll l, ll r) {
	if (r<s || e<l) return 0;
	if (l<=s && e <= r) return tree[root];
	ll mid = (s + e) / 2;
	return query(root*2, s, mid, l, r) + query(root*2+1, mid+1, e, l, r);
}

ll update(ll root, ll s, ll e, ll before, ll after) {
	if (before<s || e<before) return tree[root];
	if (before == s && before == e) return tree[root] = after;
	ll mid = (s + e) / 2;
	return tree[root] = update(root * 2, s, mid, before, after) + update(root * 2 + 1, mid + 1, e, before, after);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	rep(i, n)
		cin >> arr[i];
	init(1, 1, n);
	rep(i, m + k) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c);
		}
		else {
			cout << query(1, 1, n, b, c) << '\n';
		}
	}
}