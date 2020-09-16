#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int> > g;
bool visited[1001];
void initVisited(int n) {
	for (int i = 0; i <= n; i++)
		visited[i] = false;
}
void dfs(int n) {
	if (visited[n]) return;
	visited[n] = true;
	cout << n << ' ';
	for (int i : g[n])
		dfs(i);
}
void bfs(int n) {
	queue<int> q;
	visited[n] = true;
	q.push(n);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << ' ';
		
		for (int next : g[current]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int v, e, s;
	cin >> v >> e >> s;
	g.resize(v+1);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(auto it : g)
		sort(it.begin(), it.end());
	dfs(s);
	initVisited(v);
	cout << endl;
	bfs(s);
}