#include <iostream>
#include <algorithm>
using namespace std;
long long n, ans = -1, arr[10001], dp[10001];
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[2] + arr[1];
//	ans = max(dp[1], dp[2]);

	/*
		�ݷ�
		6
		1000 1000 1 1 1000 1000
	*/
	for (int i = 3; i <= n; i++) {
		// 1. i��° �� ����
		dp[i] = arr[i] + max(arr[i - 1] + dp[i - 3], dp[i - 2]);
		// 2. i���� �� �� ����
		dp[i] = max(dp[i - 1], dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
}