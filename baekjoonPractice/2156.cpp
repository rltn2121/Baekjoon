#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];
int dp[3][10001];
int main() {
	int n;
	cin >> n;
	int arr[10001];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0][0] = 0;
	dp[1][0] = dp[2][0] = dp[0][1] = arr[0];
	dp[1][1] = arr[1];
	dp[2][1] = arr[0] + arr[1];


	for (int i = 2; i < n; i++) {
		dp[0][i] = max(dp[0][i-1],max(dp[1][i - 1], dp[2][i - 1]));
		dp[1][i] = arr[i] + dp[0][i-1];
		dp[2][i] = arr[i] + dp[1][i-1];
	}

	cout << max(dp[0][n-1],max(dp[1][n-1], dp[2][n-1])) << endl;
	
}