#include <iostream>
using namespace std;
int dp[5001];

int initDP(int n) {
	dp[0] = -1;
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;
	for (int i = 6; i <= n; i++) {
		int a3 = dp[i - 3];
		int a5 = dp[i - 5];

		if (a3 == -1)
			a3 = 999999;
		if (a5 == -1)
			a5 = 999999;
		
		if (a3 ==999999 && a5==999999)
			dp[i] = -1;
		else
			dp[i] = (a3 < a5 ? a3 + 1 : a5 + 1);
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << initDP(n) << endl;
}