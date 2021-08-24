#include <iostream>
#define ll long long
#define mid (s+e)/2
#define rep(i,n) for(ll i=1;i<=n;i++)
using namespace std;
ll n, m, k, arr[1000000], tree[4000000+1], lazy[4000000+1];

ll init(ll root, ll s, ll e) {
	if (s == e) return tree[root] = arr[s];
	return tree[root] = init(root * 2, s, mid) + init(root * 2 + 1, mid + 1, e);
}
//void updateLazy(ll root, ll s, ll e) {
//	if (lazy[root] != 0) {
//		tree[root] += (e - s + 1) * lazy[root];
//		if (s != e) {
//			lazy[root * 2] += lazy[root];
//			lazy[root * 2 + 1] += lazy[root];
//		}
//		lazy[root] = 0;
//	}
//}
void updateLazy(ll root, ll s, ll e) {
	if (lazy[root] != 0) {
		tree[root] += (e - s + 1) * lazy[root];
		if (s != e) {
			lazy[root * 2] += lazy[root];
			lazy[root * 2 + 1] += lazy[root];
		}
		lazy[root] = 0;
	}
}

ll query(ll root, ll s, ll e, ll l, ll r) {
	updateLazy(root, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[root];
	return query(root * 2, s, mid, l, r) + query(root * 2 + 1, mid + 1, e, l, r);
}
//ll updateRange(ll root, ll s, ll e, ll l, ll r, ll val) {
//	updateLazy(root, s, e);
//	if (r < s || e < l) return tree[root];
//	if (l <= s && e <= r) {
//		tree[root] += (e - s + 1) * val;
//		if (e != s) {
//			lazy[root * 2] += val;
//			lazy[root * 2 + 1] += val;
//		}
//		return tree[root];
//	}
//	/*updateRange(root * 2, s, mid, l, r, val);
//	updateRange(root * 2 + 1, mid + 1, e, l, r, val);
//	tree[root] = tree[root * 2] + tree[root * 2 + 1];*/
//
//	return tree[root] = updateRange(root * 2, s, mid, l, r, val) + updateRange(root * 2 + 1, mid + 1, e, l, r, val);
//}
void updateRange(ll root, ll s, ll e, ll l, ll r, ll val) {
	updateLazy(root, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		tree[root] += (e - s + 1) * val;
		if (s != e) {
			lazy[root * 2] += val;
			lazy[root * 2 + 1] += val;
		}
		return;
	}

	updateRange(root * 2, s, mid, l, r, val);
	updateRange(root * 2+1, mid+1, e, l, r, val);
	tree[root] = tree[root * 2] + tree[root * 2 + 1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	rep(i, n)
		cin >> arr[i];
	init(1, 1, n);
	rep(i, m+k) {
		ll a, b, c, d;
		cin >> a>>b>>c;
		if (a == 1) {
			cin >> d;
			updateRange(1, 1, n, b, c, d);
		}
		else
			cout << query(1, 1, n, b, c) << '\n';
	}
}