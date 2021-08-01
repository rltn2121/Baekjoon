#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
vector<vector<int> > v;
int n, a, b, visited[1000001];
int dp[1000001][2];	// dp[i][0]: 본인이 얼리어답터가 아님	-> 이웃 모두 얼리어답터
					// dp[i][1]: 본인이 얼리어답터임		-> 얼리어답터 상관없음
void func(int now) {
	dp[now][1] = 1;
	for (int next : v[now]) {
		if (!visited[next]) {
			visited[next] = 1;
			func(next);
			dp[now][0] += dp[next][1];
			dp[now][1] += min(dp[next][0], dp[next][1]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.resize(n + 1);
	rep(i, n-1) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = 1;
	func(1);
	cout << min(dp[1][0], dp[1][1]);
}