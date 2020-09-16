#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int> > graph;
bool visited[1001] = { false, };
void dfs(int x) {
	if (visited[x]) return;
	cout << x << ' ';
	visited[x] = true;
	for (int i : graph[x])
		dfs(i);
}
void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			if (visited[graph[x][i]]) continue;
			q.push(graph[x][i]);
			visited[graph[x][i]] = true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(null);
	int n, m, k;
	cin >> n >> m >> k;

	graph.resize(n+1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(k);
	cout << '\n';
	for (int i = 0; i <= n; i++)
		visited[i] = false;
	bfs(k);
}