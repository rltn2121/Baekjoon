#include <iostream>
#include <algorithm>
using namespace std;
int n, ans;
int arr[100001];
int dp[100001][2];
// dp[i][0]: 원소 제거 안한 누적합
// dp[i][1]: 원소 제거한 누적 합
//			1) 내꺼 빼고 앞에는 안뺀거 선택 (dp[i-1][0])
//			2) 내꺼 안빼고 앞에는 뺀거 선택 (arr[i] + dp[i-1][1])
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	ans = dp[0][0] = dp[0][1] = arr[0];
	for (int i = 1;i < n;i++) {
		dp[i][0] = arr[i] + max(0, dp[i - 1][0]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	cout << ans;
}