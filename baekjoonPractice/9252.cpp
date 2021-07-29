#include <iostream>
#include <algorithm>
#include <stack>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
string a, b;
stack<char> s;
int dp[1002][1002];
void lcs_length() {
	rep(i, b.length()) {
		rep(j, a.length()) {
			if (b[i - 1] == a[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int len = dp[b.length()][a.length()];
	cout << len << '\n';
}
void lcs_find() {
	int i = b.length();
	int j = a.length();
	while (dp[i][j] > 0) {
		if (b[i - 1] == a[j - 1]) {
			s.push(b[i - 1]);
			i--, j--;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1]) i--;
			else j--;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	lcs_length();
	lcs_find();
}