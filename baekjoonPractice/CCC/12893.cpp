#include <iostream>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
vector<vector<int> > v;
queue<int> q;
int status[2001];
int n, m, a, b;
void func(int x) {
	status[x] = 1;
	q.push(x);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : v[now]) {
			if (status[now] == status[next]) {
				cout << 0;
				exit(0);
			}
			if (status[next] != 0) continue;
			status[next] = 3-status[now];
			q.push(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	rep(i, m) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	rep(i, n) {
		if (status[i]==0)
			func(i);
	}
	cout << 1;
}