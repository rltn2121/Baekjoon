#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pii pair<int, int>
using namespace std;
int n, ans = -1;
pii arr[16];
void dfs(int now, int sum) {
	ans = max(ans, sum);
	for (int i = now; i <= n; i++) {					// 모든 날짜 다 탐색
		if (i + arr[i].first <= n+1)					// 현재 상담이 n+1일 안에 끝나면
			dfs(i + arr[i].first, sum + arr[i].second);	// 그 날짜로 이동, 돈 더함
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n)
		cin >> arr[i].first >> arr[i].second;
	dfs(1, 0);
	cout << ans;
}