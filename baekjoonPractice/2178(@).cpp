#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;
int n, m, cnt;
int arr[100][100], visited[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
queue<pii> q;
void bfs(int i, int j) {
	q.push({ i,j });
	visited[i][j] = 1;
	while (!q.empty()) {
		cnt++;
		// 단계별로 진행
		int size = q.size();
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			// 끝에 도착
			if (x == n - 1 && y == m - 1) {
				cout << cnt;
				return;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (!visited[nx][ny] && arr[nx][ny]) {
						visited[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	bfs(0,0);
}

