#include <iostream>
#define ll long long
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
ll n, arr[1000001], b, c, ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n)
		cin >> arr[i];

	cin >> b >> c;
	rep(i, n) {
		// 총 감독관
		arr[i] -= b;
		ans++;

		// 부 감독관
		if (arr[i] > 0) {
			ll temp = (arr[i] / c);
			arr[i] -= temp * c;
			ans += temp;
			if (arr[i] > 0)
				ans++;
		}
	}
	cout << ans;
}