#include <iostream>
#include <queue>
#define pii pair<int, int>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m;
char arr[21][21];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
bool visited[20][20][20][20];
queue<pii> q;
void bfs() {
	int cnt = 1;
	while (!q.empty()) {
		int size = q.size() / 2;	// 한 번에 두 개 꺼냄
		while (size--){
			if (cnt > 10)			// 10번 초과하면 불가
				return;
			pii c1 = q.front();
			q.pop();
			pii c2 = q.front();
			q.pop();

			if (c1 == c2)			// 두 동전이 겹치면 패스
				continue;

			rep(i, 4) {
				int nx1 = c1.first + dx[i];
				int ny1 = c1.second + dy[i];
				int nx2 = c2.first + dx[i];
				int ny2 = c2.second + dy[i];

				bool drop1 = false;
				bool drop2 = false;
				if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= m)
					drop1 = true;
				if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= m)
					drop2 = true;

				if (drop1 && drop2)	// 둘 다 떨어지면 패스
					continue;

				else if ((drop1 && !drop2) || (!drop1 && drop2)) {	// 하나만 떨어짐
					cout << cnt;
					exit(0);
				}

				if (arr[nx1][ny1] == '#' && arr[nx2][ny2] == '#') continue; // 둘 다 벽이면 패스

				if (arr[nx1][ny1] != '#' && arr[nx2][ny2] != '#') {			// 둘 다 벽 아니면 이동
					if (!visited[nx1][ny1][nx2][ny2]) {
						q.push({ nx1, ny1 });
						q.push({ nx2, ny2 });
						visited[nx1][ny1][nx2][ny2] = 1;
					}
				}
				else if(arr[nx1][ny1] == '#' && arr[nx2][ny2] != '#') {		// 둘 중 하나가 벽이면
					if (!visited[c1.first][c1.second][nx2][ny2]) {			
						q.push(c1);											// 벽이면 제자리 삽입
						q.push({ nx2, ny2 });								// 벽 아니면 다음 위치 삽입
						visited[c1.first][c1.second][nx2][ny2] = 1;
					}
				}
				else if (arr[nx1][ny1] != '#' && arr[nx2][ny2] == '#') {
					if (!visited[nx1][ny1][c2.first][c2.second]) {
						q.push({ nx1, ny1 });
						q.push(c2);
						visited[nx1][ny1][c2.first][c2.second] = 1;
					}
				}
					
			}
		}
		cnt++;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') 
				q.push({ i, j });
		}
	}
	if (q.size() == 1) {	// 입력된 동전 위치가 하나 -> 두 개의 동전이 겹침
		cout << -1;
		exit(0);
	}
	bfs();
	cout << -1;
}