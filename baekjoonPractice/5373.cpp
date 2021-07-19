#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
enum {U, D, L, R, F, B};
char cube[6][3][3];
int t, n;
string cmd;

// 큐브 초기화
void init() {
	rep(i, 3) {
		rep(j, 3) {
			cube[U][i][j] = 'w';
			cube[D][i][j] = 'y';
			cube[L][i][j] = 'g';
			cube[R][i][j] = 'b';
			cube[F][i][j] = 'r';
			cube[B][i][j] = 'o';
		}
	}
}

// 큐브 출력
void print() {
	rep(i, 3) {
		rep(j, 3)
			cout << cube[U][i][j];
		cout << '\n';
	}
}

// 표면 회전
void rot(char surface, char dir) {
	char temp[3][3];
	int pos;
	if (surface == 'U')
		pos = U;
	else if (surface == 'F')
		pos = F;
	else if (surface == 'L')
		pos = L;
	else if (surface == 'B')
		pos = B;
	else if (surface == 'R')
		pos = R;
	else if (surface == 'D')
		pos = D;
	
	// 시계방향 회전
	if (dir == '+') {
		rep(i, 3) {
			temp[0][i] = cube[pos][2 - i][0];
			temp[2][i] = cube[pos][2 - i][2];
			temp[1][i] = cube[pos][2 - i][1];
		}
	}
	// 반시계방향 회전
	else {
		rep(i, 3) {
			temp[0][i] = cube[pos][i][2];
			temp[2][i] = cube[pos][i][0];
			temp[1][i] = cube[pos][i][1];
		}
	}
	rep(i, 3) {
		rep(j, 3)
			cube[pos][i][j] = temp[i][j];
	}
}
void func(string cmd) {
	char temp[3];

	// 표면 회전시킴
	rot(cmd[0], cmd[1]);

	// 윗면 시계방향일 때 인접한 면 회전
	if (cmd == "U+") {
		rep(i, 3)
			temp[i] = cube[F][0][i];

		rep(i, 3) 
			cube[F][0][i] = cube[R][0][i];
		rep(i, 3)
			cube[R][0][i] = cube[B][0][i];
		rep(i, 3)
			cube[B][0][i] = cube[L][0][i];
		rep(i, 3)
			cube[L][0][i] = temp[i];
	}

	// 윗면 반시계방향일 때 인접한 면 회전
	else if (cmd == "U-") {
		rep(i, 3)
			temp[i] = cube[F][0][i];

		rep(i, 3) 
			cube[F][0][i] = cube[L][0][i];
		rep(i, 3)
			cube[L][0][i] = cube[B][0][i];
		rep(i, 3)
			cube[B][0][i] = cube[R][0][i];
		rep(i, 3)
			cube[R][0][i] = temp[i];
	}

	// 아랫면 시계방향일 때 인접한 면 회전
	else if (cmd == "D+") {
		rep(i, 3)
			temp[i] = cube[F][2][i];

		rep(i, 3) 
			cube[F][2][i] = cube[L][2][i];
		rep(i, 3)
			cube[L][2][i] = cube[B][2][i];
		rep(i, 3)
			cube[B][2][i] = cube[R][2][i];
		rep(i, 3)
			cube[R][2][i] = temp[i];
	}
	// 아랫면 반시계방향일 때 인접한 면 회전
	else if (cmd == "D-") {
		rep(i, 3)
			temp[i] = cube[F][2][i];

		rep(i, 3)
			cube[F][2][i] = cube[R][2][i];
		rep(i, 3)
			cube[R][2][i] = cube[B][2][i];
		rep(i, 3)
			cube[B][2][i] = cube[L][2][i];
		rep(i, 3)
			cube[L][2][i] = temp[i];
	}

	// 왼쪽 시계방향일 때 인접한 면 회전
	else if (cmd == "L+") {
		rep(i, 3)
			temp[i] = cube[U][i][0];

		rep(i, 3) 
			cube[U][i][0] = cube[B][2-i][2];
		rep(i, 3)
			cube[B][i][2] = cube[D][2-i][0];
		rep(i, 3)
			cube[D][i][0] = cube[F][i][0];
		rep(i, 3)
			cube[F][i][0] = temp[i];
	}

	// 왼쪽 반시계방향일 때 인접한 면 회전
	else if (cmd == "L-") {
		rep(i, 3)
			temp[i] = cube[U][i][0];

		rep(i, 3) 
			cube[U][i][0] = cube[F][i][0];
		rep(i, 3)
			cube[F][i][0] = cube[D][i][0];
		rep(i, 3)
			cube[D][i][0] = cube[B][2-i][2];
		rep(i, 3)
			cube[B][i][2] = temp[2-i];
	}

	// 오른쪽 시계방향일 때 인접한 면 회전
	else if (cmd == "R+") {
		rep(i, 3)
			temp[i] = cube[U][i][2];

		rep(i, 3) 
			cube[U][i][2] = cube[F][i][2];
		rep(i, 3)
			cube[F][i][2] = cube[D][i][2];
		rep(i, 3)
			cube[D][i][2] = cube[B][2-i][0];
		rep(i, 3)
			cube[B][i][0] = temp[2-i];
	}

	// 오른쪽 반시계방향일 때 인접한 면 회전
	else if (cmd == "R-") {
		rep(i, 3)
			temp[i] = cube[U][i][2];

		rep(i, 3) 
			cube[U][i][2] = cube[B][2-i][0];
		rep(i, 3)
			cube[B][i][0] = cube[D][2-i][2];
		rep(i, 3)
			cube[D][i][2] = cube[F][i][2];
		rep(i, 3)
			cube[F][i][2] = temp[i];
		
	}

	// 앞면 시계방향일 때 인접한 면 회전
	else if (cmd == "F+") {
		rep(i, 3)
			temp[i] = cube[U][2][i];

		rep(i, 3) 
			cube[U][2][i] = cube[L][2-i][2];
		rep(i, 3)
			cube[L][i][2] = cube[D][0][i];
		rep(i, 3)
			cube[D][0][i] = cube[R][2-i][0];
		rep(i, 3)
			cube[R][i][0] = temp[i];
		
	}

	// 앞면 반시계방향일 때 인접한 면 회전
	else if (cmd == "F-") {
		rep(i, 3)
			temp[i] = cube[U][2][i];

		rep(i, 3) 
			cube[U][2][i] = cube[R][i][0];
		rep(i, 3)
			cube[R][i][0] = cube[D][0][2-i];
		rep(i, 3)
			cube[D][0][i] = cube[L][i][2];
		rep(i, 3)
			cube[L][i][2] = temp[2-i];
	}

	// 뒷면 시계방향일 때 인접한 면 회전
	else if (cmd == "B+") {
		rep(i, 3)
			temp[i] = cube[U][0][i];

		rep(i, 3)
			cube[U][0][i] = cube[R][i][2];
		rep(i, 3)
			cube[R][i][2] = cube[D][2][2-i];
		rep(i, 3)
			cube[D][2][i] = cube[L][i][0];
		rep(i, 3)
			cube[L][i][0] = temp[2-i];

	}

	// 뒷면 반시계방향일 때 인접한 면 회전
	else if (cmd == "B-") {
		rep(i, 3)
			temp[i] = cube[U][0][i];

		rep(i, 3) 
			cube[U][0][i] = cube[L][2-i][0];
		rep(i, 3)
			cube[L][i][0] = cube[D][2][i];
		rep(i, 3)
			cube[D][2][i] = cube[R][2-i][2];
		rep(i, 3)
			cube[R][i][2] = temp[i];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		init();
		cin >> n;
		rep(i, n) {
			cin >> cmd;
			func(cmd);
		}
		print();
	}
}