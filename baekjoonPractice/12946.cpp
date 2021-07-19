#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, ans;
int dx[] = {-1, -1, 0, 1, 1, 0 };
int dy[] = {0, 1, 1, 0, -1, -1 };
char arr[51][51];
int visited[51][51];								// 0: �湮 ����, 1: ù ��° ����, 2: �� ��° ����

void dfs(int x, int y, int direction, int val) {	// direction: ���� ĭ -> ���� ĭ � �������� �̵��ߴ°�?
	visited[x][y] = val;							// visited[][]�� ���� ���� ĥ�ϱ�
	if (direction != -1) {							// dfs ù ���� ��, �̵��� ���� �����Ƿ� -1�� ����. 
		// ������ �� ĭ�� Ȯ��						// -1�� �ƴϸ� ���� ĭ���� ���� ĭ���� �̵������� �ǹ�
		int chk1 = (direction + 2) % 6;
		int chk2 = (direction + 4) % 6;
		
		// ù ��° ĭ Ȯ��
		int nx1 = x + dx[chk1];
		int ny1 = y + dy[chk1];
		if (nx1 > 0 && nx1 <= n && ny1 > 0 && ny1 <= n && arr[nx1][ny1] == 'X') {
			cout << 3;
			exit(0);
		}

		// �� ��° ĭ Ȯ��
		int nx2 = x + dx[chk2];
		int ny2 = y + dy[chk2];
		if (nx2 > 0 && nx2 <= n && ny2 > 0 && ny2 <= n && arr[nx2][ny2] == 'X') {
			cout << 3;
			exit(0);
		}
	}

	// ������ 6���� Ž��
	rep(i,6) {
		if ((i+3)%6 == direction) continue;				// �ٷ� ���� �������� �ǵ��ư��� �ʵ���
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		// ����� ĭ ������
		if (nx > 0 && nx <= n && ny > 0 && ny <= n && arr[nx][ny] == 'X') {
			if (visited[nx][ny]) {						// ���� ĭ �̹� �湮 ������ (�� ���� ������)
				if (visited[x][y] == visited[nx][ny]) {	// ���� ĭ�� ���� ĭ ������ ������
					cout << 3;							// ���� �ϳ� �� ����ؾ� �� (3��)
					exit(0);
				}
			}
			else {										// ���� ĭ �湮 ��������
				ans = 2;								// ���� 2���� ������ ��
				int next_val = (val == 1) ? 2 : 1;		// ���� ���� �ٸ� ������ ����
				dfs(nx, ny, i, next_val);				// ���� Ž��
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
				ans = max(ans, 1);		// ù ��° dfs ȣ�� �� ans = 2�� �ٲ�µ�
				dfs(i, j, -1, 1);		// �� ��° dfs ȣ�� �� ans = 1�� ��� ����� �ʱ� ���ؼ� ans = max(ans, 1) 
			}
		}
	}
	cout << ans;
}