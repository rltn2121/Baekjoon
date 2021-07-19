#include <iostream>
#include <cstring>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int arr[5][4][4], direction[5], k, n, dir, ans;
void rotate(int num, int dir) {
	int temp = arr[num][0][2];
	// 시계
	if (dir == 1) {
		arr[num][0][2] = arr[num][0][1];
		arr[num][0][1] = arr[num][0][0];
		arr[num][0][0] = arr[num][1][0];
		arr[num][1][0] = arr[num][2][0];
		arr[num][2][0] = arr[num][2][1];
		arr[num][2][1] = arr[num][2][2];
		arr[num][2][2] = arr[num][1][2];
		arr[num][1][2] = temp;
	}
	// 반시계
	else if (dir == -1) {
		arr[num][0][2] = arr[num][1][2];
		arr[num][1][2] = arr[num][2][2];
		arr[num][2][2] = arr[num][2][1];
		arr[num][2][1] = arr[num][2][0];
		arr[num][2][0] = arr[num][1][0];
		arr[num][1][0] = arr[num][0][0];
		arr[num][0][0] = arr[num][0][1];
		arr[num][0][1] = temp;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	rep(i, 4) {
		char c;
		cin >> c;
		arr[i][0][1] = c - '0';
		cin >> c;
		arr[i][0][2] = c - '0';
		cin >> c;
		arr[i][1][2] = c - '0';
		cin >> c;
		arr[i][2][2] = c - '0';
		cin >> c;
		arr[i][2][1] = c - '0';
		cin >> c;
		arr[i][2][0] = c - '0';
		cin >> c;
		arr[i][1][0] = c - '0';
		cin >> c;
		arr[i][0][0] = c - '0';
	}
	cin >> k;
	while (k--) {
		memset(direction, 0, sizeof(direction));
		cin >> n >> dir;
		direction[n] = dir;
		// 1. 왼쪽 확인
		for (int i = n; i > 1; i--) {
			if (arr[i][1][0] == arr[i - 1][1][2]) {
				direction[i - 1] = 0;
				break;
			}
			direction[i - 1] = direction[i] * -1;
		}

		// 2. 오른쪽 확인
		for (int i = n; i < 4; i++) {
			if (arr[i][1][2] == arr[i + 1][1][0]) {
				direction[i + 1] = 0;
				break;
			}
			direction[i + 1] = direction[i] * -1;
		}
		// 3. 회전시키기
		rep(i, 4)
			rotate(i, direction[i]);
	}

	rep(i, 4)
		ans += arr[i][0][1] * (1 << (i-1));
	cout << ans;
}