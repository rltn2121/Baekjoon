 https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14500-%ED%85%8C%ED%8A%B8%EB%A1%9C%EB%AF%B8%EB%85%B8
#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, arr[501][501], val=0, ans = 0;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ex[4][4] = {
	{0, 0, 0, -1}, // で
	{0, 1, 2, 1}, // た
	{0, 0, 0, 1}, // ぬ
	{0, -1, 0, 1} // っ
};
int ey[4][4] = {
	{0, 1, 2, 1}, // で
	{0, 0, 0, 1}, // た
	{0, 1, 2, 1}, // ぬ
	{0, 1, 1, 1} // っ
};
bool visited[501][501];
void dfs(int x, int y, int cnt) {
	if (cnt == 4) {
		ans = max(ans, val);
		return;
	}

	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!visited[nx][ny]) {
				visited[nx][ny] = 1;
				val += arr[nx][ny];
				dfs(nx, ny, cnt + 1);
				val -= arr[nx][ny];
				visited[nx][ny] = 0;
			}
		}
	}
}
void func2(int x, int y) {
	rep(i, 4) {
	int cnt = 0, temp = 0;
		rep(j, 4) {
			int nx = x + ex[i][j];
			int ny = y + ey[i][j];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				temp += arr[nx][ny];
				cnt++;
			}
		}
		if (cnt == 4)
			ans = max(ans, temp);
	}
}

void func1(int x, int y) {
	int temp = 0;
	// で
	if (x - 1 >= 0 && x < n && y >= 0 && y + 2 < m) {
		temp = arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x][y + 2];
		ans = max(ans, temp);
	}
	// た
	if (x >= 0 && x + 2 < n && y >= 0 && y + 1 < m) {
		temp = arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+1][y + 1];
		ans = max(ans, temp);
	}
	// ぬ
	if (x >= 0 && x + 1 < n && y >= 0 && y + 2 < m) {
		temp = arr[x][y] + arr[x][y + 1] + arr[x +1][y + 1] + arr[x][y + 2];
		ans = max(ans, temp);
	}
	// っ
	if (x - 1 >= 0 && x + 1 < n && y >= 0 && y + 1 < m) {
		temp = arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x+1][y + 1];
		ans = max(ans, temp);
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> arr[i][j];
		}
	}

	rep(i, n) {
		rep(j, m) {
			if (!visited[i][j]) {
				visited[i][j] = 1;
				val += arr[i][j];
				dfs(i, j, 1);
				func2(i, j);
				val -= arr[i][j];
				visited[i][j] = 0;
			}
		}
	}
	cout << ans;
}