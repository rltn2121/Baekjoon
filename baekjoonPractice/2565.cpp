#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define pii pair<int, int>
using namespace std;
pii arr[101];
int arr2[101];
int dp[101];
vector<vector<int> > v(501);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);

	int cnt = 0;
	for (int i = 0; i < n; i++)
		dp[i] = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j].second > arr[i].second) {
				dp[j] = max(dp[i] + 1, dp[j]);
				cnt = max(cnt, dp[j]);
			}
		}
	}
	cout << n-cnt;
}	