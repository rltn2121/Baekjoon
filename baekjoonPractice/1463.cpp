#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
void initdp(int n) {
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		int a = (i % 3 == 0 ? dp[i / 3]+1 : 9999999);
		int b = (i % 2 == 0 ? dp[i / 2]+1 : 9999999);
		int c = dp[i - 1]+1;
		dp[i] = min(a, min(b, c));
	}
}
int main() {
	int n;
	cin >> n;
	initdp(n);
	cout << dp[n] << endl;
}