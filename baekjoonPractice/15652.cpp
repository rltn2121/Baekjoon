#include <iostream>
using namespace std;
int m, n, arr[9];
void dfs(int x, int cnt) {
	if (cnt == n) {
		for (int i = 0;i < cnt;i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = x; i <= m;i++) {
		arr[cnt] = i;
		dfs(i, cnt + 1);
	}
}
int main() {
	cin >> m >> n;
	dfs(1, 0);
}