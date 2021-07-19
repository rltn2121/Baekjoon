#include <iostream>
#include <algorithm>
using namespace std;
int m, n, arr[9], list[9];
bool visited[9];
void dfs(int x, int cnt) {
	if (cnt == n) {
		for (int i = 0;i < cnt;i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			arr[cnt] = list[i];
			visited[i] = 1;
			dfs(i, cnt + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> m >> n;
	for (int i = 0;i < m; i++)
		cin >> list[i];
	sort(list, list + m);
	dfs(0, 0);
}