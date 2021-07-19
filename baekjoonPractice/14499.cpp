#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
#define TOP dice[1][1]
#define BOTTOM dice[3][1]
using namespace std;
int n, m, x, y, k, arr[21][21], dice[4][3], cmd;
int dx[] = { 0, 0, 0, -1, 1 };	// 1: 동, 2: 서, 3: 북, 4: 남
int dy[] = { 0, 1, -1, 0, 0 };
void move(int cmd) {			// 주사위 변경
	int temp;
	// 1. 동쪽
	if (cmd == 1) {
		temp = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = temp;
	}
	// 2. 서쪽
	else if (cmd == 2) {
		temp = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = temp;
	}
	// 3. 북쪽
	else if (cmd == 3) {
		temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = temp;
	}
	// 4. 남쪽
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
		int nx = x + dx[cmd];			// 이동할 방향 설정
		int ny = y + dy[cmd];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {	// 범위 검사
			move(cmd);
			if (arr[nx][ny] == 0)		// 현재 위치가 0이면
				arr[nx][ny] = BOTTOM;	// 주사위 바닥 숫자 복사

			else {						// 현재 위치 0 아니면
				BOTTOM = arr[nx][ny];	// 현재 위치 숫자를 주사위 바닥에 복사하고
				arr[nx][ny] = 0;		// 현재 위치 0으로 변경
			}
			cout << TOP << '\n';
			x = nx;
			y = ny;
		}
	}
}