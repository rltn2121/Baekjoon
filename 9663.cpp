#include <iostream>
#include <cstring>
using namespace std;

int n;
int x_pos[16];
int y_pos[16];
int dfs(int x, int y) {
	// 1. 조건 검사 (현재까지 진행된 라인까지만 검사)
	for (int i = 0; i < x; i++) {
		// i번째 줄의 x 좌표와 현재 x 좌표가 같다면
		if (x_pos[i] == x)
			return 0;
		// i번째 줄의 y 좌표와 현재 y 좌표가 같다면
		if (y_pos[i] == y)
			return 0;
		// i번째 줄의 대각선 위치가 같다면
		// 대각선일 경우 x, y좌표 위치가 동일하게 증가(감소)함
		// (x 좌표 변화량 == y 좌표 변화량) -> 같은 대각선 상에 있음
		if (abs(x - x_pos[i]) == abs(y - y_pos[i]))
			return 0;
	}

	// 2. 제일 아랫줄 도착
	if (x == n-1)
		return 1;
	
	// 3. 현재 말의 위치 저장
	// x번째 줄에서의 좌표(x,y) 저장
	x_pos[x] = x, y_pos[x] = y;

	int cnt = 0;
	// 4. 다음 라인 탐색
	for (int i = 0; i < n; i++) {
		cnt += dfs(x + 1, i);
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ans += dfs(0, i);
	}
	cout << ans;
}