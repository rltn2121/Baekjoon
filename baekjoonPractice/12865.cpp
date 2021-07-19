#include <iostream>
#include <algorithm>
using namespace std;

int weight[101];
int value[101];
int dp[101][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	int N, K;
	cin >> N >> K;
	for (int i = 1;i <= N;i++) {
		cin >> weight[i] >> value[i];
	}

	// ��ǥ: ���Ը� j�� �����
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			// ���� ���� �� ����
			if (weight[i] > j)
				dp[i][j] = dp[i - 1][j];

			// ���� ���� ���� �� ����
			else
				dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i-1][j]);
		}
	}
	cout << dp[N][K];
}