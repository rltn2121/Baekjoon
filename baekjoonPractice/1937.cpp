#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ans, n, arr[501][501], dp[501][501];
bool visited[501][501];
// dp[i][j]: i, j���� �� �� �ִ� �ִ� ����
int dfs(int x, int y) {
	visited[x][y] = 1;
	dp[x][y]++;
	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// �̵� �Ұ�
		if (nx < 0 || ny >= n || ny < 0 || ny >= n || arr[x][y] >= arr[nx][ny]) continue;

		// ����� ������ ���
		if (visited[nx][ny])
			dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);

		// ����� �ؾ��ϴ� ���
		else 
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	return dp[x][y];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		rep(j, n) 
			cin >> arr[i][j];
	}

	rep(i, n) {
		rep(j, n) {
			if (!visited[i][j]) 
				dfs(i, j);
		}
	}

	rep(i, n) {
		rep(j, n)
			ans = max(ans, dp[i][j]);
	}
	cout << ans;
}