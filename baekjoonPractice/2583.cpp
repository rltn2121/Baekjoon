#include <iostream>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int m, n, k, cnt;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visited[101][101];
priority_queue<int, vector<int>, greater<int> > q;
void dfs(int x, int y) {
	cnt++;
	visited[x][y] = 1;
	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!visited[nx][ny]) 
				dfs(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k;
	rep(i,k){
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		// 입력 받은 영역 채우기
		for (int i = lx; i < rx; i++) {
			for (int j = ly; j < ry; j++) 
				visited[i][j] = 1;
			
		}
	}

	int ans = 0;
	rep(i, n) {
		rep(j, m) {
			if (!visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				q.push(cnt);
				ans++;
			}
		}
	}
	cout << ans << '\n';
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
}