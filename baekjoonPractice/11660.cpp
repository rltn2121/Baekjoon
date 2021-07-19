#include <iostream>
using namespace std;
int dp[1025][1025];
int n, m, a1, a2, b1, b2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			int x;
			cin >> x;
			dp[i][j] = x + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	while (m--) {
		cin >> a1 >> b1 >> a2 >> b2;
		cout << dp[a2][b2] -dp[a2][b1-1]-dp[a1-1][b2]+dp[a1-1][b1-1]<< '\n';
	}
}