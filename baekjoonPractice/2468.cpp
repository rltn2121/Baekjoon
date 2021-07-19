#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, h, arr[101][101];
bool visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void dfs(int x, int y) {
	visited[x][y] = 1;
	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (arr[nx][ny] > h && !visited[nx][ny])
				dfs(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int min_height = 101, max_height = -1;
	rep(i, n) {
		rep(j, n) {
			cin >> arr[i][j];
			if (arr[i][j] < min_height)
				min_height = arr[i][j];
			if (arr[i][j] > max_height)
				max_height = arr[i][j];
		}
	}
	int ans = 1;
	// 최소 높이 ~ 최대 높이 한 번씩 다 해봄
	for (int k = min_height; k <= max_height; k++) {
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		h = k;
		rep(i, n) {
			rep(j, n) {
				// 도시가 강수량보다 높으면
				if (arr[i][j] > k && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}