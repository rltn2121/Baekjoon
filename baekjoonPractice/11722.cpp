#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[1001], dp[1001], ans = 1;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
