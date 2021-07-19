#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int n, m, r, c, d, ans, arr[51][51];	// 0: û�� �ȵ�, 1: ��, 2: û�� �Ϸ�
void dfs(int x, int y, int dir) {
	if (arr[x][y] == 0) {				// ���� ĭ û��
		arr[x][y] = 2;
		ans++;
	}
	
	int i = 0;
	for (i = 0; i < 4; i++) {
		int nx = x + dx[dir];			// ����ĭ�� x��ǥ
		int ny = y + dy[dir];			// ����ĭ�� y��ǥ
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (arr[nx][ny] == 0) {				// ���� û�� �ؾ��ϸ�
				dir = (dir + 3) % 4;			// �������� ȸ��
				dfs(nx, ny, dir);				// �������� �̵�
			}
		
			else								// ���� û�� ���ص� �Ǹ�
				dir = (dir + 3) % 4;			// ȸ����Ű��
		}
	}
	if (i == 4) {								// �� ���� Ȯ���ߴµ� û���� �� ������
		dir = (dir + 3) % 4;					// ó�� ������ ���⿡�� ����
		int nx = x + dx[dir];					// == �������� �� �� ȸ����Ų ���¿��� ���� �������� �̵�
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (arr[nx][ny] == 1) {				// �� ������ ��� ����
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