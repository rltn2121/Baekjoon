#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pii pair<int, int>
#define MAX 200000000
using namespace std;
int n, e, a, b, c, v1, v2, ans1, ans2, dist[801];
struct cmp {
	bool operator()(const pii& a, const pii& b) {
		return a.second > b.second;
	}
};
vector<vector<pii> > vec;
priority_queue<pii, vector<pii>, cmp> pq;
void dijk(int start) {
	fill(dist, dist + n + 1, MAX);
	pq.push({ start, 0 });
	dist[start] = 0;
	while (!pq.empty()) {
		int now_v = pq.top().first;
		int now_w = pq.top().second;
		pq.pop();
		if (dist[now_v] < now_w) continue;
		for (pii next : vec[now_v]) {
			int next_v = next.first;
			int next_w = next.second + now_w;
			if (dist[next_v] > next_w) {
				dist[next_v] = next_w;
				pq.push({ next_v, next_w });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> e;
	vec.resize(n + 1);
	rep(i, e) {
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	bool poss1 = true, poss2 = true;
	dijk(1);
	ans1 += dist[v1];
	ans2 += dist[v2];

	dijk(v1);
	ans1 += dist[v2];
	ans2 += dist[n];

	dijk(v2);
	ans1 += dist[n];
	ans2 += dist[v1];
	int ans = min(ans1, ans2);
	cout << (ans >= MAX ? -1 : ans);
		
}