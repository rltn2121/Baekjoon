#include <iostream>
#include <algorithm>
#define pii pair<int, int>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, arr[9][9], temp, ans= 987654321;
pii cctvs[9];
int cnt;
bool visited[9][9];
void lookDirection(int x, int y, int direction, int cmd) {
	while (x >= 0 && x < n && y >= 0 && y < m) {
		if (arr[x][y] == -6) break;
		if (arr[x][y] < 0) {
			if (direction == 0) y++;
			else if (direction == 1) x++;
			else if (direction == 2) y--;
			else if (direction == 3) x--;
			continue;
		}
		// 우
		if (direction == 0) {
			if (cmd)
				arr[x][y++]++;
			else
				arr[x][y++]--;
		}
		// 하
		else if (direction == 1) {
			if (cmd)
				arr[x++][y]++;
			else
				arr[x++][y]--;
		}
		// 좌
		else if (direction == 2) {
			if (cmd)
				arr[x][y--]++;
			else
				arr[x][y--]--;
		}
		// 상
		else if (direction == 3) {
			if (cmd)
				arr[x--][y]++;
			else
				arr[x--][y]--;
		}
	}
}
void look(int x, int y, int cctv, int direction, int cmd) {
	// direction: 0, 1, 2, 3
	if (cctv == -1) {
		lookDirection(x, y, direction, cmd);
	}
	// direction: 0, 1
	else if (cctv == -2) {
		lookDirection(x, y, direction, cmd);
		lookDirection(x, y, (direction+2)%4, cmd);
	}

	// direction: 0, 1, 2, 3
	else if (cctv == -3) {
		lookDirection(x, y, direction, cmd);
		lookDirection(x, y, (direction + 1) % 4, cmd);
	}

	// direction: 0, 1, 2, 3
	else if (cctv == -4) {
		lookDirection(x, y, direction, cmd);
		lookDirection(x, y, (direction + 1) % 4, cmd);
		lookDirection(x, y, (direction + 2) % 4, cmd);
	}

	// direction: 
	else if (cctv == -5) {
		lookDirection(x, y, 0, cmd);
		lookDirection(x, y, 1, cmd);
		lookDirection(x, y, 2, cmd);
		lookDirection(x, y, 3, cmd);
	}
}
int zeros() {
	int ret = 0;
	rep(i, n) {
		rep(j, m)
			if (arr[i][j] == 0) ret++;
	}
	return ret;
}
void dfs(int x, int y, int idx) {
	if (idx == cnt) {
		ans = min(ans, zeros());
		return;
	}
	int rotate = 4;
	int i = cctvs[idx].first;
	int j = cctvs[idx].second;
	int cctv = arr[i][j];

	if (cctv == -2)
		rotate = 2;

	else if (cctv == -5)
		rotate = 1;

	rep(k, rotate) {
		look(i, j, cctv, k, 1);
		visited[i][j] = 1;
		dfs(i, j, idx+1);
		visited[i][j] = 0;
		look(i, j, cctv, k, 0);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> temp;
			arr[i][j] = temp * -1;			// arr[i][j]: cctv가 감시 가능한 영역이면 + 1
			if(temp>=1&&temp<=5)			// cctv 번호, 벽과 겹칠 수 있으므로, (입력) * -1 해서 음수로 저장
				cctvs[cnt++] = { i,j };
		}
	}
	dfs(0, 0, 0);
	cout << ans;
}