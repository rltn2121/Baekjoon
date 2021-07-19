// https://kosaf04pyh.tistory.com/236
#include <iostream>
using namespace std;
int n, dp[31];
int main() {
	cin >> n;
	if (n % 2 == 1) {
		cout << 0;
		exit(0);
	}
	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i++) {
		// 1. ������ 2�� ����
		dp[i] = dp[i - 2] * 3;
		// 2. �����ʿ� 4��, 6��, ..., n�� ����	
		for (int j = 4; i >= j; j = j + 2) 
			dp[i] += dp[i - j] * 2;
	}
	cout << dp[n];
}