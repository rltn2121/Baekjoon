#include <iostream>
#include <cstring>
using namespace std;
int n, k;
int coin[200];
int dp[20000][200];

void init() {
	memset(dp, 999999, sizeof(dp));
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
}
// price�� ����� �ּ� ���� ã��
int getMin(int price) {
	int min = 999999;
	for (int i = 0; i < n; i++)
		min = min < dp[price][i] ? min : dp[price][i];
	return min;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			// ����� ���� �ݾ�
			int price = coin[j];

			// ���� �ݾ� == ����� ���� �ݾ�
			if (i == price)
				dp[i][j] = 1;

			else if (i - price >= 0) {
				int min = getMin(i-price);
				dp[i][j] = min + 1;
			}
		}
	}

	int ans = getMin(k);
	cout << (ans>=999999? -1 : ans);
}