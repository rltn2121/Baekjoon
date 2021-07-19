#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, ans;
struct board {
	int arr[21][21];
	
	// 90도 회전
	void rotate() {
		int temp[21][21];
		rep(i, n) {
			rep(j, n)
				temp[i][j] = arr[n - j - 1][i];
		}

		rep(i, n) {
			rep(j, n)
				arr[i][j] = temp[i][j];
		}
	}

	// 한 쪽으로 옮기기
	void move() {
		int temp[21][21];
		// 열 단위(세로줄)로 처리
		rep(j, n) {
			bool flag = 0;	// 합칠 수 있는가?
			int row = -1;	// temp[][]의 현재 row
			rep(i, n) {
				if (arr[i][j] == 0) continue;
				if (flag && arr[i][j] == temp[row][j]) {	// 합칠 수 있음 + arr[i] == temp[row]
					temp[row][j] *= 2;						// 현재 row에서 합치기
					flag = 0;								// 합칠 수 없도록 변경
				}
				else {
					temp[++row][j] = arr[i][j];				// 현재 row에서 못 합치므로, 다음 row로 이동
					flag = 1;								// 합칠 수 있도록 변경
				}
			}

			for (int k = row + 1; k < n; k++)				// 빈 칸 채우기
				temp[k][j] = 0;
			
		}

		rep(i, n) {
			rep(j, n)
				arr[i][j] = temp[i][j];
		}
	}

	// 최댓값
	int getMax() {
		int ret = 0;
		rep(i, n) {
			rep(j, n)
				ret = max(ret, arr[i][j]);
		}
		return ret;
	}
};

void dfs(board b, int cnt) {
	if (cnt == 5) {
		ans = max(ans, b.getMax());
		return;
	}

	rep(i, 4) {
		// 원본을 이동시키면 안됨
		board next = b;
		next.move();
		dfs(next, cnt + 1);
		// 원본 회전시키기
		b.rotate();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	board b;
	cin >> n;
	rep(i, n) {
		rep(j, n)
			cin >> b.arr[i][j];
	}
	dfs(b, 0);
	cout << ans;
}