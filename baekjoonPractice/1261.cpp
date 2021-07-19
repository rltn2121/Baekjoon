// https://chanhuiseok.github.io/posts/baek-17/
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
#define rep(i,n) for(int i=1;i<=n;i++)
#define MAX 987654321
using namespace std;
int n, m, arr[101][101], dist[101][101];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
queue<pii> q;
void bfs() {
	q.push({ 1, 1 });
	dist[1][1] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && nx <= m && ny > 0 && ny <= n) {
				// 1. 1 (벽)
				if (arr[nx][ny] == 1) {
					if (dist[x][y] + 1 < dist[nx][ny]) {	// (현재 위치에서 다음 위치로 이동하는 비용) vs (이전에 찾아놓은 다음 위치로 이동하는 비용)
						dist[nx][ny] = dist[x][y] + 1;
						q.push({ nx, ny });
					}
				}
				// 2. 0 (통로)
				else {
					if (dist[x][y] < dist[nx][ny]) {		// (현재 위치에서 다음 위치로 이동하는 비용) vs (이전에 찾아놓은 다음 위치로 이동하는 비용)
						dist[nx][ny] = dist[x][y];
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, m) {
		rep(j, n) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
			dist[i][j] = MAX;
		}
	}
	bfs();
	cout << dist[m][n];
}