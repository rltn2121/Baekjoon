#include <iostream>
using namespace std;
int m, n, arr[9];
bool visited[9];
void dfs(int x, int cnt) {
	if (cnt == n) {
		for (int i = 0;i < cnt;i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (!visited[i]) {
			arr[cnt] = i;
			visited[i] = 1;
			dfs(i+1, cnt + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> m >> n;
	dfs(1, 0);
}