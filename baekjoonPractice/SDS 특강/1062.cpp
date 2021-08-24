#include <iostream>	
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, k;
vector<vector<int> > v;
bool visited[26];
int ans;
void dfs(int now, int cnt) {
	if (cnt == k) {
		int temp = 0;
		for (vector<int> vec : v) {
			bool flag = true;
			for (int i : vec) {
				if (!visited[i]) {
					// fail
					flag = false;
					break;
				}
			}
			if (flag)
				temp++;
		}
		ans = max(ans, temp);
		return;
	}

	for (int i = now; i < 26; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		dfs(i + 1, cnt + 1);
		visited[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	v.resize(n);
	rep(i, n) {
		memset(visited, 0, sizeof(visited));
		string str;
		cin >> str;
		for (char c : str) {
			int now = c - 'a';
			// antic, 중복빼고 저장
			if (visited[now] || c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') continue;
			visited[now] = 1;
			v[i].push_back(now);
		}
	}
	if (k < 5) {
		cout << 0 << '\n';
		return 0;
	}
	memset(visited, 0, sizeof(visited));
	visited['a' - 'a'] = 1;
	visited['n' - 'a'] = 1;
	visited['t' - 'a'] = 1;
	visited['i' - 'a'] = 1;
	visited['c' - 'a'] = 1;
	dfs(0, 5);
	cout << ans;
}