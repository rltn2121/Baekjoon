#define INF 1e9
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int coin[101];
int dp[100001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	for (int j = 1; j <= k; j++)
		// dp[]를 최댓값으로 초기화 
		dp[j] = INF;

	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		// coin[i]를 dp 배열의 인덱스로 사용
		for (int j = coin[i]; j <= k; j++) {
			// dp[] -> 최댓값으로 초기화 되있음.
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == INF)
		cout << -1;
	else
		cout << dp[k];
}