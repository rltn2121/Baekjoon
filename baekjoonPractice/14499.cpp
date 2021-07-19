#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
#define TOP dice[1][1]
#define BOTTOM dice[3][1]
using namespace std;
int n, m, x, y, k, arr[21][21], dice[4][3], cmd;
int dx[] = { 0, 0, 0, -1, 1 };	// 1: ��, 2: ��, 3: ��, 4: ��
int dy[] = { 0, 1, -1, 0, 0 };
void move(int cmd) {			// �ֻ��� ����
	int temp;
	// 1. ����
	if (cmd == 1) {
		temp = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = temp;
	}
	// 2. ����
	else if (cmd == 2) {
		temp = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = temp;
	}
	// 3. ����
	else if (cmd == 3) {
		temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = temp;
	}
	// 4. ����
	else if (cmd == 4) {
		temp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	rep(i, n) {
		rep(j, m)
			cin >> arr[i][j];
	}
	while (k--) {
		cin >> cmd;
		int nx = x + dx[cmd];			// �̵��� ���� ����
		int ny = y + dy[cmd];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {	// ���� �˻�
			move(cmd);
			if (arr[nx][ny] == 0)		// ���� ��ġ�� 0�̸�
				arr[nx][ny] = BOTTOM;	// �ֻ��� �ٴ� ���� ����

			else {						// ���� ��ġ 0 �ƴϸ�
				BOTTOM = arr[nx][ny];	// ���� ��ġ ���ڸ� �ֻ��� �ٴڿ� �����ϰ�
				arr[nx][ny] = 0;		// ���� ��ġ 0���� ����
			}
			cout << TOP << '\n';
			x = nx;
			y = ny;
		}
	}
}