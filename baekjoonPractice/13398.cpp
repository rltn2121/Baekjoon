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
//		dp[0][i]: ���� ���� ���� ������
//		dp[1][i]: ���� ���� �� ������
//		  1) i��° ���� -> 1 ~ i-1 �����ϸ� �ȵ� (dp[0][i-1])
//		  2) i��° ���� -> 1 ~ i-1 �� �ϳ� �����ؾ� �� (arr[i] + dp[1][i-1])
//	*/
//	for (int i = 1;i < n;i++) {
//		dp[0][i] = arr[i] + max(0, dp[0][i-1]);
//		dp[1][i] = max(dp[0][i-1], dp[1][i-1] + arr[i]);
//		ans = max(ans, max(dp[0][i], dp[1][i]));
//	}
//	cout << ans;
//}