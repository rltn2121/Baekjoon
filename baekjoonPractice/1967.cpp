#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define pr pair<int, int>
using namespace std;
vector<vector<pr> > g;
int dist[10001];
void dfs(int current, int distance) {
	for (pr p : g[current]) {
		int next = p.first;
		int dist_to_next = p.second;
		if (dist[next] == -1) {
			dist[next] = dist[current] + dist_to_next;
			dfs(next, dist_to_next);
		}
	}
}

void bfs(int n, int distance) {
	queue<pr> q;
	q.push({ n, distance });
	while (!q.empty()) {
		pr current = q.front();
		q.pop();
		for (pr p : g[current.first]) {
			int next = p.first;
			int dist_to_next = p.second;
			if (dist[next] == -1) {
				q.push({ next, dist_to_next });
				dist[next] = dist[current.first] + dist_to_next;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	g.resize(n + 1);
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i < n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back({ b,w });
		g[b].push_back({ a,w });
	}
	dist[1] = 0;
	//dfs(1, 0);
	bfs(1, 0);
	int max = -1;
	int maxIdx = -1;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > max) {
			max = dist[i];
			maxIdx = i;
		}
	}
	memset(dist, -1, sizeof(dist));
	dist[maxIdx] = 0;
	//dfs(maxIdx, 0);
	bfs(maxIdx, 0);
	for (int i = 1; i <= n; i++)
		max = max > dist[i] ? max : dist[i];
	cout << max << '\n';
}