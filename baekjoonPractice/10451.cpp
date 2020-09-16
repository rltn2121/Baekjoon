#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > g;
bool visited[1001];
int cnt = 0;
void dfs(int n, int start) {
	if (visited[n]) {
		cnt++;
		return;
	}
	
	visited[n] = true;
	for (int i : g[n])
	{
		//if (i == start)
			//cnt++;
		dfs(i, start);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		int n;
		cin >> n;
		g.clear();
		g.resize(n + 1);
		for (int i = 0; i <= n; i++)
			visited[i] = 0;
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			g[i].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if(!visited[i])
				dfs(i, i);
		}
			
		cout << cnt << '\n';
	}
}