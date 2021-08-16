#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int, int>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, arr[101][101], min_height=1e9, max_height=-1, ans, cnt;
int visited[101][101];
void bfs(int i, int j, int height) {
	queue<pii> q;
	q.push({ i,j });
	while (!q.empty()) {
		pii now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;
		rep(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			if(arr[nx][ny]>height)
				q.push({ nx,ny });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		rep(j, n) {
			cin >> arr[i][j];
			min_height = min(min_height, arr[i][j]);
			max_height = max(max_height, arr[i][j]);
		}
	}

	ans = 1;
	for (int h = min_height; h <= max_height; h++) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		rep(i, n) {
			rep(j, n) {
				if (!visited[i][j] && arr[i][j]>h) {
					bfs(i,j,h);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}