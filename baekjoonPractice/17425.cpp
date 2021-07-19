// https://rudruddl.tistory.com/m/524
#include <iostream>
using namespace std;
long long t, n, dp[1000001], sum[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	/*
		 1 ~ 1,000,000���� �̸� ä������
		 1�� ��� ���ڿ� �� ���ԵǱ� ������
		 i = 2���� �����ϸ� 1,000,000�� ��ŭ ���� ���ص� ��
	 */
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		// ���� ������� ���� ä������
		for (int j = 1; i * j <= 1000000; j++) {
			dp[i * j] += i;
		}
		// 1�� ���� ä����
		dp[i] += (dp[i - 1] + 1);
	}

	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		cout << dp[n] << '\n';
	}
}