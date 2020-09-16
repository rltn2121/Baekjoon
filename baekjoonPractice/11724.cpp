#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > g;
bool visited[1000];
void dfs(int n) {
	if (visited[n]) return;
	visited[n] = true;
	for (int i : g[n])
		dfs(i);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int v, e;
	cin >> v >> e;
	g.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}