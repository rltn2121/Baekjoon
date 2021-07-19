#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001], dp[1001], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	
	ans = dp[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + arr[i]);
				ans = max(ans, dp[i]);
			}
		}
	}
	cout << ans;
}