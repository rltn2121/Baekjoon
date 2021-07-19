#include <iostream>
#include <algorithm>
using namespace std;
int n, ans, arr[1001], dp[1001], dp_rev[1001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = dp_rev[i] = 1;
	}

	// 1. 증가하는 수열 찾기
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	// 2. 역순으로 증가하는 수열 찾기 (감소하는 수열 찾기 -> 틀림!!)
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n; j > i; j--) {
			if (arr[i] > arr[j])
				dp_rev[i] = max(dp_rev[i], dp_rev[j] + 1);
		}
	}

	// 3. 두개 더함
	for (int i = 1; i <= n; i++) {
		dp[i] += dp_rev[i];
		ans = max(ans, dp[i]);
	}
	cout << ans - 1;
}