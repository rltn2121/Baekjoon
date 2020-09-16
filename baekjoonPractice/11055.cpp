#include <iostream>
using namespace std;
int dp[1001];
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + arr[i])
					dp[i] = dp[j] + arr[i];
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++)
		max = (max > dp[i] ? max : dp[i]);
	cout  << max << '\n';
}