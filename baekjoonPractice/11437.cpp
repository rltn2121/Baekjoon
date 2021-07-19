#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pii pair<int, int>
using namespace std;
vector<vector<int> > v;
int n, m, parent[50001], depth[50001];
bool visited[50001];
void bfs(int x) {
	queue<int> q;
	int d = 0;
	q.push(x);
	visited[x] = 1;
	parent[x] = -1;
	depth[x] = d;
	while (!q.empty()) {
		d++;
		int size = q.size();
		while (size--) {
			int now = q.front(); q.pop();
			for (int i : v[now]) {
				if (visited[i]) continue;
				q.push(i);
				visited[i] = 1;
				parent[i] = now;
				depth[i] = d;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.resize(n + 1);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(1);


	cin >> m;
	rep(i, m) {
		int a, b,x,y;
		cin >> a >> b;
		if (depth[a] > depth[b]) {
			x = a;
			y = b;
		}
		else {
			x = b;
			y = a;
		}

		while (depth[x] > depth[y]) 
			x = parent[x];
		
		while (x != y) {
			x = parent[x];
			y = parent[y];
		}
		cout << x << '\n';
	}
}