#include <iostream>
#include <queue>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int, int>
using namespace std;
int t, m, n, k, cnt;
int arr[51][51];
bool visited[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int x, int y) {
	cnt++;
	queue<pii> q;
	q.push({ x, y });
	visited[x][y] = true;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		int x = now.first;
		int y = now.second;
		rep(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (arr[nx][ny]==1 && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		cin >> m >> n >> k;
		rep(i, k) {
			int a, b;
			cin >> a >> b;
			arr[b][a] = 1;
		}

		rep(i,n){
			rep(j, m) {
				if (arr[i][j] == 1 && !visited[i][j])
					bfs(i, j);
			}
		}
		cout << cnt << '\n';
	}
}


