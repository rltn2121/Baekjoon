#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll n, dp[100001];

int main() {
	cin >> n;
	fill(dp, dp + n + 1, 987654321);
	for (int i = 1; i * i <= n; i++)
		dp[i * i] = 1;

	// 1부터 n까지 채우기
	for (int i = 1; i <= n; i++) {
		// i 만들 수 있는 모든 경우의 수 다 해보기
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
	}
	cout << dp[n];
}