#include <iostream>
using namespace std;
int dp[12][12];
int func(int n, int k) {
	if (dp[n][k] != 0)
		return dp[n][k];
	if (k == 0)
		return 1;
	if (k == 1) {
		dp[n][k] = n;
		return n;
	}
	if (k == n) {
		dp[n][k] = 1;
		return 1;
	}
	return func(n - 1, k) + func(n - 1, k - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	cout << func(n, k);
}