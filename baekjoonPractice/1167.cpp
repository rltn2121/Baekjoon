#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int> > > v;
int dist[100001];
bool visited[100001];
void dfs(int n, int distance) {
	if (visited[n]) return;
	visited[n] = true;
	dist[n] = distance;
	for (pair<int, int> p : v[n])
		dfs(p.first, p.second + distance);
}

void bfs(int n) {
	queue<pair<int, int> > q;
	q.push(make_pair(n, 0));
	visited[n] = true;
	dist[n] = 0;
	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		dist[current.first] = current.second;
		for (pair<int, int> next : v[current.first]) {
			if (!visited[next.first]) {
				q.push(make_pair(next.first, current.second + next.second));
				visited[next.first] = true;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int idx, a, b;
		cin >> idx >> a;
		while (a != -1) {
			cin >> b;
			v[idx].push_back(make_pair(a, b));
			v[a].push_back(make_pair(idx, b));
			cin >> a;
		}
	}
	//dfs(1, 0);
	bfs(1);
	int max = -1;
	int maxIdx = -1;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > max) {
			max = dist[i];
			maxIdx = i;
		}
		dist[i] = 0;
		visited[i] = false;
	}
	
	//dfs(maxIdx, 0);
	bfs(maxIdx);
	for (int i = 1; i <= n; i++) 
		max = (max > dist[i] ? max : dist[i]);
	
	cout << max << '\n';
}