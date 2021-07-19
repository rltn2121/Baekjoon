#include <iostream>
using namespace std;
int arr[1001];
int dp[1001];
int n;
int max_length = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			// ������ �� �� �� ����
			if (arr[j] > arr[i])
				dp[j] = (dp[i] + 1 > dp[j]) ? dp[i] + 1 : dp[j];
		}
		// �ִ� ���� ����
		max_length = max_length > dp[i] ? max_length : dp[i];
	}
	cout << max_length + 1;
}