#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, arr[51][51], ans;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int visited[51][51];
void input();
void dfs(int x, int y, int cnt) {
	// 무한번 이동가능
	if (cnt > n*m) {
		cout << -1;
		exit(0);
	}

	// dp 체크
	if (cnt <= visited[x][y]) return;

	// 방문 처리
	ans = max(ans, cnt);
	visited[x][y] = cnt;
	rep(i, 4) {
		int nx = x + dx[i]*arr[x][y];
		int ny = y + dy[i]*arr[x][y];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == -1) continue;
		dfs(nx, ny, cnt+1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	dfs(0, 0, 1);
	cout << ans;
}

void input() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			char c;
			cin >> c;
			if (c == 'H') arr[i][j] = -1;
			else arr[i][j] = c - '0';
		}
	}
}