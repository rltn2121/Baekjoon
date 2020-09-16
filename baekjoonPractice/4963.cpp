#include <iostream>
#include <queue>
using namespace std;
int island[50][50];
bool visited[50][50];
int w, h;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void clear() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			island[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x,y });
	visited[x][y] = true;
	
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (island[nx][ny] && !visited[nx][ny])
				{
					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}
	}
}
void dfs(int x, int y) {
	if (visited[x][y] || island[x][y]==0) return;
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < h && 0 <= ny && ny < w) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> w >> h;
	while (true) {
		if (w == 0 && h == 0)
			break;
		clear();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				cin >> island[i][j];
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) 	{
				if (!visited[i][j] && island[i][j] == 1) {
					//dfs(i, j);
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cin >> w >> h;
	}
}