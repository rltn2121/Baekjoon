#include <iostream>
using namespace std;
int n, k;
int dp[1001][1001];
int nCr(int n, int k) {
	if (dp[n][k] != 0) return dp[n][k];
	if (k == 0) return 1;
	if (n == k) return 1;
	return dp[n][k] = (nCr(n - 1, k) + nCr(n - 1, k - 1)) % 10007;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	cout << nCr(n, k);
}