#include <iostream>
#include <stack>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
stack<int> s;
int n, ans, idx, arr[1001], dp[1001], index[1001];
void func(int idx) {
	if (idx == -1) return;
	s.push(arr[idx]);
	func(index[idx]);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n) {
		cin >> arr[i];
		dp[i] = 1;
		index[i] = -1;
	}

	rep(i, n) {
		rep(j,i){
			if (arr[i] > arr[j]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					index[i] = j;
				}
			}
		}
	}

	// dp ÃÖ´ñ°ª, ÀÎµ¦½º Ã£±â
	rep(i, n) {
		if (dp[i] > ans) {
			ans = dp[i];
			idx = i;
		}
	}
	cout << ans << '\n';
	// index ¹è¿­ Å½»ö
	func(idx);
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}