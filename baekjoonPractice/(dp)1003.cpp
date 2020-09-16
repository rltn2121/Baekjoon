#include <iostream>
using namespace std;
typedef struct fibonacci
{
	int zero=0;
	int one=0;
}fibo;
int main() {
	fibo dp[40];
	dp[0].zero = 1;
	dp[0].one = 0;
	dp[1].zero = 0;
	dp[1].one = 1;
	
	int testCase;
	cin >> testCase;

	while (testCase)
	{
		int num;
		cin >> num;
		for (int i = 2; i <= num; i++) {
			dp[i].zero = dp[i - 1].zero + dp[i - 2].zero;
			dp[i].one = dp[i - 1].one + dp[i - 2].one;
		}

		cout << dp[num].zero << ' ' << dp[num].one << endl;
		testCase--;
	}
}