#include <iostream>
using namespace std;
int dp[11];
int initDP(int n) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	if (dp[n] != 0)
		return dp[n];
	for (int i = 4; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	
	return dp[n];
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << initDP(n) << endl;
	}
}