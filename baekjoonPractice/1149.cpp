#include <iostream>;
#include <algorithm>
using namespace std;
int n;
const int SIZE = 1001;
int color[3][SIZE], dp[3][SIZE];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> color[j][i];
	}
	dp[0][1] = color[0][1];
	dp[1][1] = color[1][1];
	dp[2][1] = color[2][1];
	for (int i = 2; i <= n; i++) {
		dp[0][i] = color[0][i] + min(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] = color[1][i] + min(dp[0][i - 1], dp[2][i - 1]);
		dp[2][i] = color[2][i] + min(dp[0][i - 1], dp[1][i - 1]);
	}
	cout << min(dp[0][n], min(dp[1][n], dp[2][n]));
}