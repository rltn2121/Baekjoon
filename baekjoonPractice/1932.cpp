#include <iostream>
#include <algorithm>
using namespace std;
int n, dp[501][501], ans = -1;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cin >> dp[i][j];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}