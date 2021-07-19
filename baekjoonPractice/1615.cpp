#include <iostream>
#include <queue>
#define rep(i,n) for(ll i=1;i<=n;i++)
#define mid (s+e)/2
#define ll long long
#define pii pair<ll, ll>
using namespace std;
ll n, m, arr[2000001], tree[8000010];
priority_queue<pii> pq;
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
	cin >> n >> m;
	rep(i, m) {
		ll a, b;
		cin >> a >> b;
		pq.push({ -a, -b });
	}

	ll idx = 1;
	while (!pq.empty()) {
		arr[idx++] = -pq.top().second; 
		pq.pop();

	}
	
	ll ans = 0;
	rep(i, m) {
		ll now = arr[i];
		ans+=query(1, 1, n, now + 1, n);
		update(1, 1, n, now, 1);
	}
	cout << ans;
}