#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001][1001];
int main() {

	int n;
	cin >> n;
	int max_arr = -1;
	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
		max_arr = (arr[i] > max_arr ? arr[i] : max_arr);
	}
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	int max_dp = -1;
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		dp[i][i] = 1;
		if (i == 0 && arr[i] == max_arr)
			continue;
		int start = arr[i];

		for (j = i + 1; j < n; j++) {
			
			if (arr[j] > start) {
				start = arr[j];
				dp[i][j] = dp[i][j - 1] + 1;
			}
			else
				dp[i][j] = dp[i][j - 1];


			if (arr[j - 1] == max_arr) {
				if (arr[j] > arr[j - 2])
					start = arr[j];
				else if (arr[j] == arr[j - 2]) {
					start = arr[j];
					dp[i][j]--;
				}
				else
					start = arr[j];
			}
		}
		max_dp = (max_dp < dp[i][j - 1] ? dp[i][j - 1] : max_dp);
	}
	cout << max_dp << endl;
}


/*for (int i = 0; i < n; i++) {
		int j = 0;
		dp[i][i] = 1;
		int start = arr[i];
		for (j = i+1; j < n; j++) {
			if (arr[j] > start) {
				if (arr[j] != max_arr)
					start = arr[j];

				dp[i][j] = dp[i][j-1] + 1;
			}
			else
				dp[i][j] = dp[i][j - 1];
		}
		max = (max < dp[i][j-1] ? dp[i][j-1] : max);
	}*/

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}

	cout << "max: " << max << endl;*/

