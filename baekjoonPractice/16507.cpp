#include <iostream>
using namespace std;
int r, c, q, r1, c1, r2, c2,x;
int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> q;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> x;
			dp[i][j] = x+dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	while (q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		int area = (r2 - r1 + 1) * (c2 - c1 + 1);
		int sum = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
		cout << sum / area << '\n';
	}
}