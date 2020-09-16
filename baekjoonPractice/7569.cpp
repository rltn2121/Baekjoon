#include <iostream>
#include <queue>
#define rep(i,n) for(int i = 0; i<n; i++)
#define piii pair<pair<int, int>, int>
#define fst first
#define snd second
#define chk(x,n) 0<=x && x<n
using namespace std;
int arr[100][100][100];
bool visited[100][100][100];
int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 0, 0, 0, 0, 1, -1 };
int dz[] = { 1, -1, 0, 0, 0, 0 };
int m, n, h;
queue<piii> q;
bool finish() {
	rep(i, h) {
		rep(j, n) {
			rep(k, m) {
				if (arr[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}
int bfs() {
	int cnt = 0;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			piii cur = q.front();
			q.pop();
			rep(i, 6) {
				int nz = cur.fst.fst + dz[i];
				int ny = cur.fst.snd + dy[i];
				int nx = cur.snd + dx[i];
				if (chk(nx, m) && chk(ny, n) && chk(nz, h) && !visited[nz][ny][nx]) {
					if (arr[nz][ny][nx] == -1) continue;
					else if (arr[nz][ny][nx] == 0) {
						arr[nz][ny][nx] = 1;
						visited[nz][ny][nx] = true;
						q.push({ { nz,ny }, nx });
					}

					
				}
			}
		}
		cnt++;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;
	rep(i, h) {
		rep(j, n) {
			rep(k, m) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ {i,j},k });
					visited[i][j][k] = true;
				}
			}
		}
	}
	int ret = bfs()-1;
	cout << (finish() ? ret : -1);
	
}