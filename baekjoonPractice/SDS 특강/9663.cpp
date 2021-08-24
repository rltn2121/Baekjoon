#include <iostream>
using namespace std;
int n, ans;

int visited[15][15];
void visit(int x, int y, int cmd) {
	for (int i = 0; i < n; i++) {
		visited[i][y] += cmd;	// »óÇÏ
		visited[x][i] += cmd;	// ÁÂ¿ì
	}
	// ¿ì»ó
	int i = x;
	int j = y;
	while (i >= 0 && i < n && j >= 0 && j < n) 
		visited[i--][j++] += cmd;
	
	// ¿ìÇÏ
	i = x;
	j = y;
	while (i >= 0 && i < n && j >= 0 && j < n)
		visited[i++][j++] += cmd;

	// ÁÂ»ó
	i = x;
	j = y;
	while (i >= 0 && i < n && j >= 0 && j < n)
		visited[i--][j--] += cmd;

	// ÁÂÇÏ
	i = x;
	j = y;
	while (i >= 0 && i < n && j >= 0 && j < n)
		visited[i++][j--] += cmd;
}
void dfs(int cnt) {
	if (cnt == n) {
		ans++;
		return;
	}

	int i;
	int j;
	for (i = cnt; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (visited[i][j]>0) continue;
			visit(i, j, 1);
			dfs(cnt + 1);
			visit(i, j, -1);
		}
		if (j == n) break;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	dfs(0);
	cout << ans;
}