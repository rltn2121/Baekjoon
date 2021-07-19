#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, arr[21][21], ans = 987654321;
int visited[21];
vector<int> v1, v2;
int team1, team2;
void dfs(int now) {
	v1.clear();
	v2.clear();
	team1 = 0;
	team2 = 0;
	// 계산
	rep(i, n) {
		if (visited[i])
			v1.push_back(i);
		else
			v2.push_back(i);
	}
	if (v1.size() == 1)
		team1 = 0;
	else {
		for (int i : v1) {
			for (int j : v1) {
				if (i == j) continue;
				team1 += arr[i][j];
			}
		}
	}
	if (v2.size() == 1)
		team2 = 0;
	else {
		for (int i : v2) {
			for (int j : v2) {
				if (i == j) continue;
				team2 += arr[i][j];
			}
		}
	}
	ans = min(ans, abs(team1 - team2));
	// 백트래킹
	for (int i = now; i <= n; i++) {
		visited[i] = 1;
		dfs(i + 1);
		visited[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n) {
		rep(j, n)
			cin >> arr[i][j];
	}
	visited[1] = 1;
	dfs(2);
	cout << ans;
}