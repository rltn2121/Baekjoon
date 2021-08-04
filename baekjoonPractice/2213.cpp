#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pii pair<int, int>

using namespace std;
vector<vector<int> > v;
vector<pii> child[10001][2];
priority_queue<int> pq;
int n, dp[10001][2], a,b;
bool visited[10001];
void input();
void print();
void dfs(int now) {
	for (int next : v[now]) {
		if (!visited[next]) {
			visited[next] = 1;
			dfs(next);

			// now 미포함
			if (dp[next][0] > dp[next][1]) {
				dp[now][0] += dp[next][0];
				child[now][0].push_back({ next,0 });
			}
			else {
				dp[now][0] += dp[next][1];
				child[now][0].push_back({ next,1 });
			}

			// now 포함
			dp[now][1] += dp[next][0];
			child[now][1].push_back({ next, 0 });
		}
	}
}

void trace(int now, int idx) {
	if (idx == 1)
		pq.push(-now);
	for (pii next : child[now][idx]) 
		trace(next.first, next.second);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	visited[1] = 1;
	dfs(1);

	if (dp[1][0] > dp[1][1]) trace(1, 0);
	else trace(1, 1);

	print();
}

void input() {
	cin >> n;
	v.resize(n + 1);
	rep(i, n)
		cin >> dp[i][1];
	rep(i, n - 1) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}
void print() {
	cout << max(dp[1][0], dp[1][1]) << '\n';
	while (!pq.empty()) {
		cout << -pq.top() << ' ';
		pq.pop();
	}
}