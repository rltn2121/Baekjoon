#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pr;
int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int arr[500][500];
bool visited[500][500];
int n;
int cnt = 0;
pr destination;
queue<pr> q;
void bfs(pr& p) {
	q.push(p);
	visited[p.first][p.second] = true;
	while (!q.empty()) {
		int curSize = q.size();
		for (int i = 0; i < curSize; i++) {
			pr current = q.front();
			q.pop();
			if (current.first == destination.first && current.second == destination.second)
				return;

			for (int i = 0; i < 8; i++) {
				int nx = current.first + dx[i];
				int ny = current.second + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (!visited[nx][ny]) {
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
					}
				}
			}
		}
		cnt++;
	}
}
void clear(int n) {
	cnt = 0;
	while (!q.empty())
		q.pop();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		clear(n);
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		pr current = make_pair(a, b);
		destination = make_pair(c, d);
		bfs(current);
		cout << cnt << endl;
	}
}