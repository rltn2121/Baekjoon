#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > g;
int state[20001];
void init(int n) {
	g.clear();
	g.resize(n + 1);
	for (int i = 0; i <= n; i++)
		state[i] = false;
}

void dfs(int current) {
	if (!state[current])
		state[current] = 1;
	
	for (int next : g[current]) {
		if (!state[next]) {
			if (state[current] == 1)
				state[next] = 2;
			else
				state[next] = 1;
			dfs(next);
		}
	}
}
bool isBipartite(vector<vector<int> > &g) {
	for (int i = 1; i < g.size(); i++) {
		for (int j : g[i]) {
			if (state[i] == state[j])
				return 0;
		}
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		init(v);
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int i = 1; i <= v; i++) {
			if(!state[i])
				dfs(i);
		}
		if (isBipartite(g))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
}