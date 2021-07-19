#include <iostream>
#include <algorithm>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[5][5], direction[5][5], visited[5][5];
int n, m;
int val = 0;
int total = 0;
int ans = -1;
int cur;
int temp = 0;
void func(int x, int y) {
	while(1){
		if (x >= n || y >= m || cur != direction[x][y]) {
			total += temp;
			temp = 0;
			return;
		}
		if (visited[x][y])
			return;
		visited[x][y] = 1;
		temp = temp * 10 + arr[x][y];
		if (direction[x][y] == 0)
			y++;
		else
			x++;
	}
}
int main() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	while (val < (1 << (n * m))) {
		// 1. val -> direction[][]
		int idx = 0;
		while (idx < n*m) {
			int nx = idx / m;
			int ny = idx % m;
			direction[nx][ny] = (val >> idx) & 1;
			idx++;
		}
		// 2. arr, direction, visited
		memset(visited, 0, sizeof(visited));
		total = 0;
		rep(i, n) {
			rep(j, m) {
				if (!visited[i][j]) {
					cur = direction[i][j];
					func(i,j);
				}
			}

		}
		ans = max(ans, total);
		val++;
	}
	cout << ans;
}