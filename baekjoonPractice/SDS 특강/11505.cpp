#include <iostream>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mid (s+e)/2
#define div 1000000007
#define ll long long
using namespace std;
ll n, m, k, arr[1000001], tree[1000001 * 4 + 1];

ll init(ll root, ll s, ll e) {
	if (s == e) return tree[root] = arr[s];
	return tree[root] = init(root * 2, s, mid) * init(root * 2 + 1, mid + 1, e) % div;
}

ll query(ll root, ll s, ll e, ll l, ll r) {
	if (r < s || e < l) return 1;
	if (l <= s && e <= r) return tree[root];
	return query(root * 2, s, mid, l, r) * query(root * 2 + 1, mid + 1, e, l, r) % div;
}

ll update(ll root, ll s, ll e, ll idx, ll num) {
	if (idx < s || e < idx) return tree[root];
	if (s == e) return tree[root] = num;
	return tree[root] = update(root * 2, s, mid, idx, num) * update(root * 2 + 1, mid + 1, e, idx, num) % div;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	rep(i, n)
		cin >> arr[i];
	init(1, 1, n);
	rep(i, m + k) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			update(1, 1, n, b, c);
		else
			cout << query(1, 1, n, b, c) << '\n';
	}
}