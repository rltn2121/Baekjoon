#include <iostream>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, k, arr[101], dp[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	rep(i, n) 
		cin >> arr[i];

	rep(i, n) {
		int coin = arr[i];
		rep(value, k) {
			if (value == coin)
				dp[value]++;
			if (value < coin) continue;
			dp[value] = dp[value] + dp[value - coin];
		}
	}
	cout << dp[k];

}