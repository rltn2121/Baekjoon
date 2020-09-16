#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int dp[1000];
	int score[301];
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf_s("%d", &score[i]);
	
	int	max1 = score[1];
	int incre1 = 0;

	int max2 = score[2];
	int incre2 = 0;

	for (int i = 4; i <= n; i++) {
		dp[i] = score[i] + max(score[i - 2] + score[i - 3], score[i - 1] + score[i - 3]);
	}
	for(int i=1; i<=n; i++)
		cout << "dp[" << i << "] = " << dp[i] << endl;
}