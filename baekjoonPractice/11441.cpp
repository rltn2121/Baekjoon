#include <iostream>
using namespace std;
int n,m;
int dp[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		dp[i] = x + dp[i - 1];
	}

	cin >> m;
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << '\n';
	}
}