#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, arr[10], ans[10];
bool visited[10];
void dfs(int cnt) {
	if (cnt == m) {
		rep(i, m)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	int before = -1;
	for (int i = 0; i < n; i++) {
		if (before == arr[i]) continue;
		if (cnt > 0 && ans[cnt - 1] > arr[i]) continue;
		if (!visited[i]) {
			visited[i] = 1;
			before = arr[i];
			ans[cnt] = arr[i];
			dfs(cnt + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i, n)
		cin >> arr[i];
	sort(arr, arr + n);
	dfs(0);
}