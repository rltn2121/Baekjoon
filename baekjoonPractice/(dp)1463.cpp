#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];

int calculate(int n) {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		int min1, min2, min3 = 99999;
		if (i % 3 != 0 && i % 2 != 0)
			dp[i] = dp[i - 1] + 1;
		else {
			if (i % 3 == 0) {
				min3 = dp[i / 3] + 1;
			}
			if (i % 2 == 0) {
				min2 = dp[i / 2] + 1;
			}
			min1 = dp[i - 1] + 1;
			dp[i] = min(min(min1, min2), min3);
		}
	}
	return dp[n];
}
int main() {
	int n;
	scanf_s("%d", &n);
	printf("%d\n", calculate(n));
	/*for (int i = 1; i <= n; i++)
		cout << "dp[" << i << "] = " << dp[i] << endl;*/
}