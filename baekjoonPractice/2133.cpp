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
		// 1. 오른쪽 2개 고정
		dp[i] = dp[i - 2] * 3;
		// 2. 오른쪽에 4개, 6개, ..., n개 고정	
		for (int j = 4; i >= j; j = j + 2) 
			dp[i] += dp[i - j] * 2;
	}
	cout << dp[n];
}