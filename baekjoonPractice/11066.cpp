#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int t, n, dp[501][501];
void input();
void func() {
	int total_diff = n - 1;

	rep(diff, total_diff) {
		rep(i, n - diff) {
			int j = i + diff;
			for (int k = i; k < j; k++) {
				int temp = dp[i][k] + dp[k + 1][j];
				if (i != k) temp += dp[i][k];
				if ((k + 1) != j) temp += dp[k + 1][j];
				if (dp[i][j] == 0 || temp < dp[i][j])
					dp[i][j] = temp;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	while (t--) {
		input();
		func();
		cout << dp[1][n] << '\n';
	}
}

void input() {
	memset(dp, 0, sizeof(dp));
	cin >> n;
	rep(i, n)
		cin >> dp[i][i];
}