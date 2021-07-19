#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k;
int coin[101];
int dp[10001];

void init() {
	memset(dp, 999999, sizeof(dp));
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			// 사용할 동전 금액
			int price = coin[j];

			// 만들 금액 == 사용할 동전 금액
			if (i == price)
				dp[i] = 1;

			else if (i - price >= 0) 
				dp[i] = min(dp[i], dp[i - price] + 1);
		}
	}

	int ans = dp[k];
	cout << (ans >= 999999 ? -1 : ans);
}