#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int r, c;
char arr[21][21];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool visited[26];
int ans = 0;
void dfs(int x, int y, int step) {
	ans = ans > step ? ans : step;
	// Å½»ö
	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			char next_char = arr[nx][ny];
			if (!visited[next_char - 'A']) {
				visited[next_char - 'A'] = true;
				dfs(nx, ny, step + 1);
				visited[next_char - 'A'] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	rep(i, r) {
		rep(j, c)
			cin >> arr[i][j];
	}
	visited[arr[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans;
}