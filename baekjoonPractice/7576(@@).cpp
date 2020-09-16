#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int arr[1000][1000];
int visited[1000][1000];
int maxVal = -1;
queue<pair<int, int> > q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (arr[nx][ny] == 0 && !visited[nx][ny]) {
					q.push({ nx, ny });
					arr[nx][ny] = arr[x][y] + 1;
					visited[nx][ny] = true;
					
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j]==1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	bfs();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				cout << -1 << endl;
				return 0;
			}
			maxVal = maxVal > arr[i][j] ? maxVal : arr[i][j];
		}
	}
	cout << maxVal-1 << endl;
}