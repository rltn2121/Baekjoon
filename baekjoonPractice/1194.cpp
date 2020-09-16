#include <iostream>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0; i<n; i++)
#define pii pair<int, int>
#define piii pair<pii, int>
#define fst first
#define snd second
#define valid(x,n) 0<=x && x < n

int n, m;
int mask;
pii src;
char arr[50][50];
bool visited[50][50][64];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
queue<piii> q;
void input() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			char c;
			cin >> c;
			arr[i][j] = c;
			if (c == '0')
				src = { i,j };
			else if (c >= 'a' && c <= 'f')
				mask += (1 << (c - 'a'));
		}
	}
}
bool hasKey(char c, int key) {
	if( (key >> (c-'a')) % 2 == 1)
		return true;
	return false;
}
int bfs(int x, int y) {
	int cnt = 1;
	q.push({ {x,y},0 });
	visited[x][y][0] = true;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			piii cur = q.front();
			q.pop();
			rep(i, 4) {
				int nx = cur.fst.fst + dx[i];
				int ny = cur.fst.snd + dy[i];
				int key = cur.snd;
				char nextChar = arr[nx][ny];
				if (valid(nx, n) && valid(ny, m) && !visited[nx][ny][key]) {
					if (nextChar == '1')
						return cnt;
					else if (nextChar == '0' || nextChar == '.') {
						q.push({ {nx, ny}, key });
						visited[nx][ny][key] = true;
					}
					else if (nextChar >= 'a' && nextChar <= 'f') {
						int newKey = key + (hasKey(nextChar, key) ? 0 : (1 << (nextChar - 'a')));
						if (!visited[nx][ny][newKey]) {
							q.push({ {nx, ny}, newKey });
							visited[nx][ny][newKey] = true;
						}
					}
					else if (nextChar >= 'A' && nextChar <= 'F') {
						if (hasKey(nextChar, key)) {
							q.push({ {nx, ny}, key });
							visited[nx][ny][key] = true;
						}
					}
				}
			}
		}
		cnt++;
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << bfs(src.fst, src.snd);
}