#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[1000];
	int dp[1000] = { 0, };
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1)
					dp[i]++;
			}
		}
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		if (dp[i] > max)
			max = dp[i];
	}

	cout << max+1 << endl;
}