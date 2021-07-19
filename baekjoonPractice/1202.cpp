#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<ll, ll>
using namespace std;
ll n, k, idx, ans;
pii arr[300001];
ll bag[300001];
priority_queue<ll> q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	rep(i,n)
		cin >> arr[i].first >> arr[i].second;
	
	rep(i,k)
		cin >> bag[i];

	sort(arr, arr + n);
	sort(bag, bag + k);

	idx = 0;
	ans = 0;
	rep(i, k) {
		while (idx < n && arr[idx].first <= bag[i])
			q.push(arr[idx++].second);
		if (!q.empty()) {
			ans += q.top();
			q.pop();

		}
	}
	cout << ans;
}