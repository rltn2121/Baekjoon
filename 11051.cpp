#include <iostream>
#include <cstdlib>
using namespace std;
int n, k;
int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(null);
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++)
			dp[i][j] = 1;
	}
	cin >> n >> k;
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k && j <= i; j++) {
			if (j == i || j == 0)
				dp[i][j] = 1;
			else if (k == 1)
				dp[i][j] = i;
			else
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}

	cout << dp[n][k];
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k && j <=i; j++)
			cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j] << '\n';
	}*/
}