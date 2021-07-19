#include <iostream>
#define DIV 9901
using namespace std;
int n, dp[3][100001];
int main() {
	cin >> n;
	dp[0][1] = 1;	// 배치 안함
	dp[1][1] = 1;	// 1번 칸에 배치
	dp[2][1] = 1;	// 2번 칸에 배치

	for (int i = 2; i <= n; i++) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % DIV;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % DIV;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % DIV;
	}
	cout << (dp[0][n] + dp[1][n] + dp[2][n]) % DIV;
	
}