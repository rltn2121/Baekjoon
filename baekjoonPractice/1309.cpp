#include <iostream>
#define DIV 9901
using namespace std;
int n, dp[3][100001];
int main() {
	cin >> n;
	dp[0][1] = 1;	// ��ġ ����
	dp[1][1] = 1;	// 1�� ĭ�� ��ġ
	dp[2][1] = 1;	// 2�� ĭ�� ��ġ

	for (int i = 2; i <= n; i++) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % DIV;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % DIV;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % DIV;
	}
	cout << (dp[0][n] + dp[1][n] + dp[2][n]) % DIV;
	
}