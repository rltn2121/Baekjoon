#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[100][100];
int dist[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void bfs(int x, int y) {
	vector<vector<pair<int, int> > >v;
	v.resize(10001);
	int level = 1;
	v[level].push_back({ x,y });
	dist[0][0] = level;
	while (!v[level].empty() || !v[level+1].empty()) {
		if (v[level].empty())
			level++;
		pair<int, int> cur = v[level].front();
		v[level].erase(v[level].begin());
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (arr[nx][ny] && !dist[nx][ny]) {
					v[level+1].push_back({ nx,ny });
					dist[nx][ny] = level+1;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	}
	bfs(0,0);
	cout << dist[n - 1][m - 1] << endl;
}

#include <iostream>
#include <queue>
using namespace std;
int n, m;
int arr[100][100];
int dist[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x,y });
	dist[0][0] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (arr[nx][ny] && !dist[nx][ny]) {
					q.push({ nx,ny });
					dist[nx][ny] = dist[cur.first][cur.second] + 1;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf_s("%1d", &arr[i][j]);
	}
	bfs(0, 0);
	cout << dist[n - 1][m - 1] << endl;
}