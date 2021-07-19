#include <iostream>
#include <queue>
#define pii pair<int, int>
#define ppii pair<pii, pii>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, cnt;
char arr[11][11];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int visited[10][10][10][10];
queue<ppii> q;
pii r, b, hole;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
				r = { i,j };
			else if (arr[i][j] == 'B')
				b = { i,j };
			else if (arr[i][j] == 'O')
				hole = { i,j };
		}
	}

	q.push({ r, b });
	visited[r.first][r.second][b.first][b.second] = 1;
	while (!q.empty()) {
		if (cnt > 10) {
			cout << -1;
			exit(0);
		}
		int size = q.size(); 
		while (size--) {
			pii now_r = q.front().first;
			pii now_b = q.front().second;
			q.pop();
			
			// ���� �� O ����������????
			if (arr[now_r.first][now_r.second] == 'O' && arr[now_b.first][now_b.second] != 'O') {
				cout << cnt;
				exit(0);
			}

			rep(i, 4) {
				int nrx = now_r.first;
				int nry = now_r.second;
				int nbx = now_b.first;
				int nby = now_b.second;

				// ���� ĭ�� �� �ƴϸ� �̵�
				while (arr[nrx + dx[i]][nry + dy[i]] != '#') {
					if (arr[nrx][nry] == 'O') break;
					nrx += dx[i];
					nry += dy[i];
				}

				// ���� ĭ�� �� �ƴϸ� �̵�
				while (arr[nbx + dx[i]][nby + dy[i]] != '#') {
					if (arr[nbx][nby] == 'O') break;
					nbx += dx[i];
					nby += dy[i];
				}


				// ������, �Ķ��� ��ġ��????????	-> �� �κ� ������ �� ǯ
				if (nrx == nbx && nry == nby) {
					if (arr[nrx][nry] != 'O') {
						// �� ���� �̵��� ���� �� ĭ �ڷ� �̵�
						int r_dist = abs(nrx - now_r.first) + abs(nry - now_r.second);
						int b_dist = abs(nbx - now_b.first) + abs(nby - now_b.second);
						if (r_dist > b_dist) {
							nrx -= dx[i];
							nry -= dy[i];
						}
						else {
							nbx -= dx[i];
							nby -= dy[i];
						}
					}
				}
				
				// �̹� �湮������ continue
				if (visited[nrx][nry][nbx][nby]) continue;

				// �湮 ó�� + ť�� ����
				visited[nrx][nry][nbx][nby] = 1;
				q.push({ {nrx, nry}, {nbx, nby} });
			}
		}
		cnt++;
	}
	cout << -1;
}