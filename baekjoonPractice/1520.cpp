#include <iostream>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int m, n;
int arr[501][501];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int dp[501][501];
int dfs(int x, int y) {
	if (x == (m - 1) && y == (n - 1))
		return 1;

	// -1: 방문 안 한 상태
	if (dp[x][y] == -1) {
		// 0: 방문 한 상태
		dp[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (arr[nx][ny] < arr[x][y])
					dp[x][y] += dfs(nx, ny);
			}
		}
	}
	
	return dp[x][y];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> m >> n;
	rep(i, m) {
		rep(j, n)
			cin >> arr[i][j];
	}
	cout << dfs(0, 0);
}