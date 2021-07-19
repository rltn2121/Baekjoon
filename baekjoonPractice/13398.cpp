//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n, ans, arr[100001], dp[2][100001];
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> n;
//	for(int i=0;i<n;i++)
//		cin >> arr[i];
//	ans = dp[0][0] = dp[1][0] = arr[0];
//	/*
//		dp[0][i]: 원소 제거 안한 연속합
//		dp[1][i]: 원소 제거 한 연속합
//		  1) i번째 제거 -> 1 ~ i-1 제거하면 안됨 (dp[0][i-1])
//		  2) i번째 포함 -> 1 ~ i-1 중 하나 제거해야 함 (arr[i] + dp[1][i-1])
//	*/
//	for (int i = 1;i < n;i++) {
//		dp[0][i] = arr[i] + max(0, dp[0][i-1]);
//		dp[1][i] = max(dp[0][i-1], dp[1][i-1] + arr[i]);
//		ans = max(ans, max(dp[0][i], dp[1][i]));
//	}
//	cout << ans;
//}