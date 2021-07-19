#include <iostream>
#define rep(i,n) for(int i=2;i<=n;i++)
using namespace std;
int dp[2][101];
int main() {
	int n;
	cin >> n;
	dp[0][1] = 1;
	dp[1][1] = 2;
	rep(i, n) {
		dp[0][i] = dp[0][i - 1] + i;
		dp[1][i] = dp[1][i - 1] + (i+1);
	}
	if (dp[0][n] % 2 == 0 && dp[1][n] % 2 == 0)
		cout << "Even";
	else if (dp[0][n] % 2 == 1 && dp[1][n] % 2 == 1)
		cout << "Odd";
	else
		cout << "Either";
}