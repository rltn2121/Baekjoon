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
		// dp[]�� �ִ����� �ʱ�ȭ 
		dp[j] = INF;

	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		// coin[i]�� dp �迭�� �ε����� ���
		for (int j = coin[i]; j <= k; j++) {
			// dp[] -> �ִ����� �ʱ�ȭ ������.
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == INF)
		cout << -1;
	else
		cout << dp[k];
}