#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int n, m, r, c, d, ans, arr[51][51];	// 0: 청소 안됨, 1: 벽, 2: 청소 완료
void dfs(int x, int y, int dir) {
	if (arr[x][y] == 0) {				// 현재 칸 청소
		arr[x][y] = 2;
		ans++;
	}
	
	int i = 0;
	for (i = 0; i < 4; i++) {
		int nx = x + dx[dir];			// 왼쪽칸의 x좌표
		int ny = y + dy[dir];			// 왼쪽칸의 y좌표
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (arr[nx][ny] == 0) {				// 왼쪽 청소 해야하면
				dir = (dir + 3) % 4;			// 왼쪽으로 회전
				dfs(nx, ny, dir);				// 왼쪽으로 이동
			}
		
			else								// 왼쪽 청소 안해도 되면
				dir = (dir + 3) % 4;			// 회전시키기
		}
	}
	if (i == 4) {								// 네 방향 확인했는데 청소할 곳 없으면
		dir = (dir + 3) % 4;					// 처음 진입한 방향에서 후진
		int nx = x + dx[dir];					// == 왼쪽으로 한 번 회전시킨 상태에서 왼쪽 방향으로 이동
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (arr[nx][ny] == 1) {				// 벽 만나면 즉시 종료
				cout << ans;
				exit(0);
			}
			dfs(nx, ny, dir);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r >> c >> d;
	rep(i, n) {
		rep(j, m)
			cin >> arr[i][j];
	}
	dfs(r, c, d);
}