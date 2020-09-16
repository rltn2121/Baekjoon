#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> v;
int arr[25][25];
bool visited[25][25];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
int area = 1;
int bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x,y });
	visited[x][y] = true;
	int cnt = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (arr[nx][ny] && !visited[nx][ny]) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
					cnt++;
				}
			}
		}
	}
	return cnt;
}
int dfs(int x, int y) {
	if (visited[x][y]) return 0;
	visited[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (arr[nx][ny])
				dfs(nx, ny);
		}
	}
	return area++;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			scanf_s("%1d", &arr[i][j]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				//v.push_back(dfs(i, j));
				v.push_back(bfs(i, j));
				cnt++;
				area = 1;
			}
		}
	}
	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (int i : v)
		cout << i << '\n';
}

