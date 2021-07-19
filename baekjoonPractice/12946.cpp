#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, ans;
int dx[] = {-1, -1, 0, 1, 1, 0 };
int dy[] = {0, 1, 1, 0, -1, -1 };
char arr[51][51];
int visited[51][51];								// 0: 방문 안함, 1: 첫 번째 색깔, 2: 두 번째 색깔

void dfs(int x, int y, int direction, int val) {	// direction: 이전 칸 -> 현재 칸 어떤 방향으로 이동했는가?
	visited[x][y] = val;							// visited[][]에 현재 색깔 칠하기
	if (direction != -1) {							// dfs 첫 실행 시, 이동한 방향 없으므로 -1로 설정. 
		// 인접한 두 칸만 확인						// -1이 아니면 이전 칸에서 현재 칸으로 이동했음을 의미
		int chk1 = (direction + 2) % 6;
		int chk2 = (direction + 4) % 6;
		
		// 첫 번째 칸 확인
		int nx1 = x + dx[chk1];
		int ny1 = y + dy[chk1];
		if (nx1 > 0 && nx1 <= n && ny1 > 0 && ny1 <= n && arr[nx1][ny1] == 'X') {
			cout << 3;
			exit(0);
		}

		// 두 번째 칸 확인
		int nx2 = x + dx[chk2];
		int ny2 = y + dy[chk2];
		if (nx2 > 0 && nx2 <= n && ny2 > 0 && ny2 <= n && arr[nx2][ny2] == 'X') {
			cout << 3;
			exit(0);
		}
	}

	// 인접한 6방향 탐색
	rep(i,6) {
		if ((i+3)%6 == direction) continue;				// 바로 이전 방향으로 되돌아가지 않도록
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		// 연결된 칸 있으면
		if (nx > 0 && nx <= n && ny > 0 && ny <= n && arr[nx][ny] == 'X') {
			if (visited[nx][ny]) {						// 다음 칸 이미 방문 했으면 (고리 형성 됐으면)
				if (visited[x][y] == visited[nx][ny]) {	// 현재 칸과 다음 칸 색깔이 같으면
					cout << 3;							// 색깔 하나 더 사용해야 함 (3개)
					exit(0);
				}
			}
			else {										// 다음 칸 방문 안했으면
				ans = 2;								// 색깔 2개만 있으면 됨
				int next_val = (val == 1) ? 2 : 1;		// 현재 색과 다른 색으로 변경
				dfs(nx, ny, i, next_val);				// 다음 탐색
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n) {
		rep(j, n)
			cin >> arr[i][j];
	}

	rep(i, n) {
		rep(j, n) {
			if (arr[i][j] == 'X' && !visited[i][j]) {
				ans = max(ans, 1);		// 첫 번째 dfs 호출 시 ans = 2로 바꿨는데
				dfs(i, j, -1, 1);		// 두 번째 dfs 호출 시 ans = 1일 경우 덮어쓰지 않기 위해서 ans = max(ans, 1) 
			}
		}
	}
	cout << ans;
}