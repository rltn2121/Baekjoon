#include <iostream>
#define DIV 1000000009
using namespace std;
long long t, n, dp[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % DIV;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}