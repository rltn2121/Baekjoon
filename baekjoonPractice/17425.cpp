// https://rudruddl.tistory.com/m/524
#include <iostream>
using namespace std;
long long t, n, dp[1000001], sum[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	/*
		 1 ~ 1,000,000까지 미리 채워넣음
		 1은 모든 숫자에 다 포함되기 때문에
		 i = 2부터 실행하면 1,000,000번 만큼 수행 안해도 됨
	 */
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		// 나의 배수에게 나를 채워넣음
		for (int j = 1; i * j <= 1000000; j++) {
			dp[i * j] += i;
		}
		// 1은 직접 채워줌
		dp[i] += (dp[i - 1] + 1);
	}

	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		cout << dp[n] << '\n';
	}
}