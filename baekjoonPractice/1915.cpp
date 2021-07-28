#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m, dp[1001][1001], ans;
void input();
void func() {
	rep(i, n) {
		rep(j, m) {
			if (dp[i][j] == 1)
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
			ans = max(ans, dp[i][j]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	func();
	cout << ans * ans;
}
void input() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			char c;
			cin >> c;
			dp[i][j]= c - '0';
		}
	}
}