#include <iostream>
using namespace std;

// 1. Àç±ÍÇÔ¼ö
/*int function(int num) {
	if (num == 1)
		return 1;
	else if (num == 2)
		return 2;
	else if (num == 3)
		return 4;
	else
		return function(num - 1) + function(num - 2) + function(num - 3);
}*/

// 2. Dynamic Programming
int dp[20] = { 0, };
int function(int num) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= num; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i-3];
	}
	return dp[num];

}
int main() {
	int testCase = 0;
	cin >> testCase;

	while (testCase > 0)
	{
		int input = 0;
		cin >> input;
		cout << function(input)<<'\n';
		testCase--;
	}
}

