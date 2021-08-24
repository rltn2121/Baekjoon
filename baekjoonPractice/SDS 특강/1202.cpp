#include <iostream>
#include <queue>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pll pair<ll, ll>

using namespace std;
ll n, k, idx, ans;
pll arr[300001];
ll bag[300001];

priority_queue<ll> pq_value;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	rep(i, n)
		cin >> arr[i].first >> arr[i].second;

	rep(i, k)
		cin >> bag[i];

	sort(arr, arr + n);
	sort(bag, bag + k);

	rep(i, k) {
		int weight = bag[i];

		while (idx < n) {
			pll now = arr[idx];
			if (now.first > weight)  break;

			pq_value.push(now.second);
			idx++;
		}
		if (!pq_value.empty()) {

			ans += pq_value.top();
			pq_value.pop();
		}
	}
	cout << ans;
}