#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, arr[301], dp[301];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n)
		cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n;i++)
		dp[i] = arr[i] + max(arr[i - 1] + dp[i - 3], dp[i - 2]);
	cout << dp[n];
}