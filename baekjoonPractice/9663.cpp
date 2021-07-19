#include <iostream>
using namespace std;
int n, ans;
int visited[15][15];
int col_visited[15];
bool chk(int x, int y) {
	int i = x+1;
	int j = y+1;
	while (i >= 0 && i < n && j >= 0 && j < n) {	// 우하 대각선
		if (visited[i++][j++])
			return false;
	}
	i = x+1;
	j = y-1;
	while (i >= 0 && i < n && j >= 0 && j < n) {	// 좌하 대각선
		if (visited[i++][j--])
			return false;
	}
	i = x-1;
	j = y+1;
	while (i >= 0 && i < n && j >= 0 && j < n) {	// 우상 대각선
		if (visited[i--][j++])
			return false;
	}

	i = x-1;
	j = y-1;
	while (i >= 0 && i < n && j >= 0 && j < n) {	// 좌상 대각선
		if (visited[i--][j--])
			return false;
	}
	return true;
}
void bfs(int row) {
	if (row == n) {
		ans++;
		return;
	}
	int j;
	for (int i = row; i < n; i++) {
		for (j = 0; j < n; j++) {
			// 세로 검사 && 대각선 검사
			if (!col_visited[j] && chk(i,j)) {
				col_visited[j] = 1;		// 열 방문 처리	
				visited[i][j] = 1;		// 퀸 놓음
				bfs(row + 1);
				visited[i][j] = 0;	
				col_visited[j] = 0;
			}
		}
		// 퀸 놓을 공간 없어서 다음 단계 진행 못하고 j가 끝까지 감
		if (j == n)
			return;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	bfs(0);
	cout << ans;
}