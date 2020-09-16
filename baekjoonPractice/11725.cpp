#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > v;
int parent[100001];
bool visited[100001];
void dfs(int n) {
	visited[n] = true;
	for (int next : v[n]) {
		if (!visited[next]) {
			parent[next] = n;
			dfs(next);
		}
	}
}

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int next : v[current]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				parent[next] = current;
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
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//dfs(1); 
	bfs(1);
	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}