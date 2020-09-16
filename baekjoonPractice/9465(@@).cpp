#include <iostream>
#include <algorithm>
using namespace std;
int price[2][100001];
int dp[3][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> price[0][i];
		for (int i = 0; i < n; i++)
			cin >> price[1][i];

		dp[0][0] = 0;
		dp[1][0] = price[0][0];
		dp[2][0] = price[1][0];
		
		for (int i = 1; i < n; i++) {
			dp[0][i] = max(dp[1][i-1], dp[2][i - 1]);
			dp[1][i] = price[0][i] + max(dp[0][i-1], dp[2][i-1]);
			dp[2][i] = price[1][i] + max(dp[0][i-1], dp[1][i-1]);
		}

		cout << max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1])) << endl;
	}
}