#include <iostream>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] <= dp[j])
					dp[i] = dp[j]+1;
			}
		}

	}
	int max = dp[0];
	for (int i = 0; i < n; i++)
		max = (max > dp[i] ? max : dp[i]);
	cout << max << endl;
}