#include <iostream>
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define mid (s+e)/2
ll n, m, arr[500001], tree[2000001], lazy[2000001];
using namespace std;
void updateLazy(ll root, ll s, ll e) {
	if (lazy[root]) {
		tree[root] ^= (e-s+1)*lazy[root];
		if (s != e) {
			lazy[root * 2] ^= lazy[root];
			lazy[root * 2 + 1] ^= lazy[root];
		}
		lazy[root] = 0;
	}
}

ll updateRange(ll root, ll s, ll e, ll l, ll r, ll val) {
	updateLazy(root, s, e);
	if (r < s || e < l) return tree[root];
	if (l <= s && e <= r) {
		tree[root] ^= (e-s+1)*val;
		if (s != e) {
			lazy[root * 2] ^= val;
			lazy[root * 2 + 1] ^= val;
		}
		return tree[root];
	}
	return tree[root] = updateRange(root * 2, s, mid, l, r, val) + updateRange(root * 2 + 1, mid + 1, e, l, r, val);
}

ll init(ll root, ll s, ll e) {
	if (s == e) return tree[root] = arr[s];
	return tree[root] = init(root * 2, s, mid) + init(root * 2 + 1, mid + 1, e);
}

ll query(ll root, ll s, ll e, ll l, ll r) {
	updateLazy(root, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[root];
	return query(root * 2, s, mid, l, r) + query(root * 2 + 1, mid + 1, e, l, r);
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
		int a, b,c,d;
		cin >> a >> b;
		if (a == 1) {
			cin >> c >> d;
			updateRange(1, 1, n, b+1, c+1, d);
		}
		else cout << query(1, 1, n, b+1, b+1) << '\n';
	}
}