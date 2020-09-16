#include <iostream>
using namespace std;
int price[1001];
int dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> price[i];
	dp[0] = 0;
	dp[1] = price[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			dp[i] = (dp[i] > dp[i - j] + price[j] ? dp[i] : dp[i - j] + price[j]);
	}
	cout << dp[n] <<'\n';
}