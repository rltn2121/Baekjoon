#include <iostream>
#include <queue>
#define ll long long
#define mid (s+e)/2
#define rep(i,n) for(ll i=1;i<=n;i++)
#define pii pair<ll, ll>
using namespace std;
ll n, arr[500001], tree[500000*4+1], ans;
priority_queue<pii> pq;
ll query(ll root, ll s, ll e, ll l, ll r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[root];
	return query(root * 2, s, mid, l, r) + query(root * 2 + 1, mid + 1, e, l, r);
}
ll update(ll root, ll s, ll e, ll idx, ll val) {
	if (idx < s || e < idx) return tree[root];
	if (idx <= s && e <= idx) {
		return tree[root] = val;
	}

	return tree[root] = update(root * 2, s, mid, idx, val) + update(root * 2 + 1, mid + 1, e, idx, val);
}

void relabeling() {
	rep(i, n)
		pq.push({ arr[i], i });

	while (!pq.empty()) {
		ll idx = pq.top().second;
		arr[idx] = pq.size();
		pq.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) 
		cin >> arr[i];
	

	relabeling();
	rep(i, n) {
		ans+= query(1, 1, n, arr[i]+1, n);
		update(1, 1, n, arr[i], 1);
	}
	cout << ans;
}