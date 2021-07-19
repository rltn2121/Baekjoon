#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m;
int arr[9][9];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int temp[9][9];
int ans = -1;
int chk_zero() {
	int ret = 0;
	rep(i, n) {
		rep(j, m) {
			if (temp[i][j] == 0)
				ret++;
		}
	}
	return ret;
}
bool visited[9][9];
void bfs() {
	queue<pii> q;
	// 1) 원본 배열 복사 (원본 배열로 하면 다음 bfs 실행 못함)
	rep(i, n) {		
		rep(j, m)	
			temp[i][j] = arr[i][j];
	}
	
	// 2) 모든 칸 탐색 (2 이고 방문 안했으면 q에 추가)
	rep(i, n) {		
		rep(j, m) {	
			if (temp[i][j] == 2 && !visited[i][j]) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}

	// 3) q에서 꺼내서 처리
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		int x = now.first;
		int y = now.second;
		rep(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (temp[nx][ny] == 0 && !visited[nx][ny]) {
					temp[nx][ny] = 2;
					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
		}
	}
}

void dfs(int x, int y, int cnt) {
	if (cnt == 3) {
		memset(visited, 0, sizeof(visited));
		bfs();						// 2. bfs로 2 퍼뜨리기
		ans = max(ans, chk_zero());	// 3. 0 개수 확인
		return;
	}
	
	for(int i = x; i<n; i++){		// 1. 벽 세우기(백트래킹)
		for(int j = 0; j<m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;	
				dfs(i, j, cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		rep(j, m)
			cin >> arr[i][j];
	}
	dfs(0, 0, 0);
	cout << ans;
}