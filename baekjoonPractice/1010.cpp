#include <iostream>
#include <cstring>
using namespace std;
int t, n, m, dp[30][30];
int nCr(int n, int k) {
	if (dp[n][k] != 0) return dp[n][k];
	if (k == 0 || n == k) return 1;
	return dp[n][k]=(nCr(n - 1, k) + nCr(n - 1, k - 1));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		cout << nCr(m, n) << '\n';
	}
}