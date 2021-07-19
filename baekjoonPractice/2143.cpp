#include <iostream>
#include <algorithm>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
ll t, n, m, ans;
ll a[1000], b[1000];
ll sum1[500501], sum2[500501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	cin >> n;
	rep(i, n) {
		ll x;
		cin >> x;
		if (i == 0) 
			a[i] = x;
		else
			a[i] = a[i - 1] + x;
	}
	cin >> m;
	rep(i, m) {
		ll x;
		cin >> x;
		if (i == 0)
			b[i] = x;
		else
			b[i] = b[i - 1] + x;
	}
	
	ll idx_a = 0;
	rep(i, n) {
		sum1[idx_a++] = a[i];
		for (ll j = 0; j < i; j++)
			sum1[idx_a++] = a[i] - a[j];
	}
	ll idx_b = 0;
	rep(i, m) {
		sum2[idx_b++] = b[i];
		for (ll j = 0; j < i; j++)
			sum2[idx_b++] = b[i] - b[j];
	}
	sort(sum1, sum1 + idx_a);
	sort(sum2, sum2 + idx_b);

	ll l = 0;
	ll r = idx_b - 1;
	ll cnt = 0;
	while (l < idx_a) {
		if (l > 0 && sum1[l] == sum1[l - 1]) {
			ans += cnt;
			l++;
		}

		else {
			while (r>=0 && sum1[l] + sum2[r] > t)
				r--;
			cnt = 0;
			while (r >= 0 && sum1[l] + sum2[r] == t) {
				cnt++;
				r--;
			}a
			ans += cnt;
			l++;
		}
	}
	cout << ans;
}