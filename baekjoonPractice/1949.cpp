#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
vector<vector<int> > v;
int n, a,b, dp[10001][2], visited[10001];
void func(int now) {
	for (int next : v[now]) {
		if (visited[next]) continue;
		visited[next] = 1;
		func(next);
		dp[now][0] += max(dp[next][0], dp[next][1]);
		dp[now][1] += dp[next][0];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.resize(n + 1);
	rep(i, n)
		cin >> dp[i][1];
	rep(i, n - 1) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = 1;
	func(1);
	cout << max(dp[1][0], dp[1][1]);
}