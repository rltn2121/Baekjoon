#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, arr[1001], dp[1001];
int main() {
	cin >> n;
	rep(i, n) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	rep(i, n) {
		rep(j, i / 2) 
			dp[i] = min(dp[i], arr[j] + dp[i - j]);
	}
	cout << dp[n];
}