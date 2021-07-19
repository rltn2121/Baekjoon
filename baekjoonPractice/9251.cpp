#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	int max_length = 0;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i-1] == b[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			max_length = max(max_length, dp[i][j]);
		}
	}
	cout << max_length;
}