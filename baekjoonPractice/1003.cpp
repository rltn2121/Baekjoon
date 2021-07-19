#include <iostream>
using namespace std;
int dp[41][2];
void func(int n) {
	if (dp[n][0] != 0) return;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		func(n);
		cout << dp[n][0] << ' ' << dp[n][1] << '\n';
 	}
}