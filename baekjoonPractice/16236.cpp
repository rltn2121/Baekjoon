// https://velog.io/@skyepodium/백준-16236-아기-상어
#include <iostream>
#include <cstring>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int, int>
using namespace std;

pii shark;
int n, arr[20][20], weight=2, eat, ans;	
int min_dist, min_x, min_y, dist[20][20];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
void init() {
	min_dist = 987654321;
	min_x = 987654321;
	min_y = 987654321;
	memset(dist, -1, sizeof(dist));
}
void upgrade() {
	weight++;
	eat = 0;
}
void bfs() {
	queue<pii> q;
	dist[shark.first][shark.second] = 0;
	q.push(shark);
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		rep(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (arr[nx][ny] > weight || dist[nx][ny] != -1) continue;
			
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx,ny });

			// 먹을 수 있음
			if (arr[nx][ny] > 0 && arr[nx][ny] < weight) {
				// 1. 더 가까움
				if (dist[nx][ny] < min_dist) {
					min_dist = dist[nx][ny];
					min_x = nx;
					min_y = ny;
				}

				// 2. 거리 같음
				else if (dist[nx][ny] == min_dist) {
					if (nx < min_x) {
						min_x = nx;
						min_y = ny;
					}
					else if (nx == min_x) {
						if (ny < min_y) {
							min_x = nx;
							min_y = ny;
						}
					}
				}
			}
		}
	}
}
void func() {
	init();
	bfs();
	if (min_x == 987654321 || min_y == 987654321) {
		cout << ans;
		exit(0);
	}
	ans += dist[min_x][min_y];
	shark = { min_x, min_y };	// 상어 위치 갱신
	arr[min_x][min_y] = 0;		// 먹음
	eat++;
	if (eat == weight)	// 업그레이드
		upgrade();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n) {
		rep(j, n) {
			int x;
			cin >> x;
			arr[i][j] = x;
			if (x == 9) {
				arr[i][j] = 0;
				shark = { i,j };
			}
		}
	}

	while (1)	// 먹을 수 있는 물고기 있으면
		func();			
}