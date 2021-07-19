#include <iostream>
using namespace std;
#define DIV 1000000009
long long t, n, dp[4][100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[1][3] = 1;
	dp[2][3] = 1;
	dp[3][3] = 1;
	for (long long i = 4; i <= 100000; i++) {
		dp[1][i] = (dp[2][i - 1] + dp[3][i - 1]) % DIV;
		dp[2][i] = (dp[1][i - 2] + dp[3][i - 2]) % DIV;
		dp[3][i] = (dp[1][i - 3] + dp[2][i - 3]) % DIV;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (dp[1][n] + dp[2][n] + dp[3][n]) % DIV << '\n';
	}
}