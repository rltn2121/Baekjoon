#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > src;
bool visited[100];
int sum = 0;
void dfs(int n) {
	if (visited[n] == true)
		return;

	visited[n] = true;
	sum++;
	for (int i = 0; i < src[n].size(); i++) {
		if (!visited[src[n][i]])
			dfs(src[n][i]);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	src.resize(n+1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		src[a].push_back(b);
		src[b].push_back(a);
	}
	dfs(1);
	cout << sum-1 << endl;


}