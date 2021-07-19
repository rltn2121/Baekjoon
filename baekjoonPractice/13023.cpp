#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b, visited[2001];
vector<vector<int> > v;
void dfs(int idx, int cnt) {
	if (cnt == 5) {
		cout << 1;
		exit(0);
	}
	for (int i : v[idx]) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i, cnt+1);
			visited[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < m;i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i, 1);
			visited[i] = 0;
		}
	}
	cout << 0;
}