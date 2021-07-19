#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int list[10];
int arr[10];
void dfs(int x, int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = x; i < m; i++) {
		arr[cnt] = list[i];
		dfs(i+1, cnt+1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> list[i];
	sort(list, list + m);
	dfs(0,0);

}