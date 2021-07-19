#include <iostream>
#define DIV 1000000000
using namespace std;
long long n, dp[101][10], ans = 0;
int main() {
	for (int i = 1; i < 10;i++)
		dp[1][i] = 1;
	cin >> n;
	for(int j = 2; j<=n;j++) {
		for (int i = 0;i < 10;i++) {
			if (i == 0) dp[j][1] += (dp[j-1][0] % DIV);
			else if (i == 9) dp[j][8] += (dp[j-1][9] % DIV);
			else {
				dp[j][i - 1] += (dp[j-1][i] % DIV);
				dp[j][i + 1] += (dp[j-1][i] % DIV);
			}
		}
	}
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[n][i]) % DIV;
	cout << ans;
}