#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll x, y, z, ans= 1000000000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;
	ll origin = y*100 / x;

	ll l = 1;
	ll r = 1000000000;
	ll mid = 0;
	if (origin >= 99) {
		cout << -1;
		return 0;
	}
	while (l <= r) {
		mid = (l + r) / 2;
		z = (y+mid)*100 / (x+mid);

		if (z <= origin) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
			ans = min(ans, mid);
		}
	}
	
	cout << ans;
}