#include <iostream>	
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
vector<vector<int> > v;
queue<int> q;
int t, n, k, target;
int build_time[1001];
int in_degree[1001];
int dp[1001];
int before[1001];
void func();
void init();
void input();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		input();
		func();
		cout << dp[target] << '\n';
	}
}

void func() {
	rep(i, n) {
		if (in_degree[i] == 0) 
			q.push(i);
		dp[i] = build_time[i];
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : v[now]) {
			in_degree[next]--;
			before[next] = max(before[next], dp[now]);
			if (in_degree[next] == 0) {
				q.push(next);
				dp[next] += before[next];
				if (next == target) return;
			}
		}
	}
}

void init() {
	v.clear();
	v.resize(n + 1);
	while (!q.empty()) q.pop();
	memset(build_time, 0, sizeof(build_time));
	memset(in_degree, 0, sizeof(in_degree));
	memset(dp, 0, sizeof(dp));
	memset(before, 0, sizeof(before));
}

void input() {
	cin >> n >> k;
	init();
	rep(i, n)
		cin >> build_time[i];
	rep(i, k) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		in_degree[b]++;
	}
	cin >> target;
}