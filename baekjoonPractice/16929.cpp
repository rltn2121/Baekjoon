#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int visited[50][50];
char arr[50][50];
void dfs(int x, int y, char c, int ban_direc) {
	// �湮�� �� �� �湮������ ����
	if (visited[x][y]) {
		cout << "Yes";
		exit(0);
	}
	visited[x][y] = 1;

	rep(i, 4) {
		// �ݴ� �������� �� ������ ����
		if (i == ban_direc) continue;

		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && c == arr[nx][ny]) {
			// �̵��ϸ� �ȵǴ� ���� ���� (����� �ݴ� ����)
			int ban = 0;
			if (i == 0) ban = 1;
			else if (i == 1) ban = 0;
			else if (i == 2) ban = 3;
			else if (i == 3) ban = 2;
			dfs(nx, ny, arr[nx][ny], ban);
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
	rep(i, n) {
		rep(j, m) {
			if (!visited[i][j])
				dfs(i, j, arr[i][j], 0);	// (row, col, ���繮��, �̵� ���� ����)
		}
	}
	cout << "No";
}