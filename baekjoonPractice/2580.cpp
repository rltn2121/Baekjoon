#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[10][10], cnt;
bool row_visited[10][10], col_visited[10][10], sqr_visited[10][10];
// 핵심
// 1. visited 검사
// 2. 백트래킹 종료 조건
int getSqrNum(int x, int y) {
	x -= x % 3;
	y -= y % 3;
	if (x == 0) {
		if (y == 0) return 0;
		if (y == 3) return 1;
		if (y == 6) return 2;
	}
	if (x == 3) {
		if (y == 0) return 3;
		if (y == 3) return 4;
		if (y == 6) return 5;
	}
	if (x == 6) {
		if (y == 0) return 6;
		if (y == 3) return 7;
		if (y == 6) return 8;
	}
}
void setVisited(int i, int j, bool flag) {
	row_visited[i][arr[i][j]] = flag;
	col_visited[j][arr[i][j]] = flag;
	sqr_visited[getSqrNum(i, j)][arr[i][j]] = flag;
}
bool chk(int x, int y, int val) {
	if (row_visited[x][val]) return false;	// 가로 검사
	if (col_visited[y][val]) return false;	// 세로 검사
	
	x -= x % 3;								// 사각형 검사
	y -= y % 3;
	if (sqr_visited[getSqrNum(x, y)][val]) return false;
	return true;
}
void print() {
	rep(i, 9) {
		rep(j, 9)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}
void dfs(int x, int y) {
	// 0 전부 없어졌으면 출력
	if (cnt == 0) {
		print();
		exit(0);
	}

	// 백트래킹
	for (int i = x; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == 0) {				// 0이면
				int k;
				for (k = 1; k <= 9; k++) {		// 1 ~ 9 다 넣어봄
					if (chk(i, j, k)) {			// 조건 맞으면 다음 단계 진행
						arr[i][j] = k;
						setVisited(i, j, 1);
						cnt--;					// 0 개수 줄이기
						dfs(i, j+1);
						cnt++;
						setVisited(i, j, 0);
						arr[i][j] = 0;			// 다시 0으로 돌리기
					}
				}
				if (k == 10) return;			// k == 10 -> 0인 칸에 숫자 넣지 못하고 반복문 끝남
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	rep(i, 9) {
		rep(j, 9) {
			cin >> arr[i][j];
			if (arr[i][j] != 0)
				setVisited(i, j, 1);			// visited 설정
			else
				cnt++;							// 0 개수 체크
		}
	}
	dfs(0, 0);
}