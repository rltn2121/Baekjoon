#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define rep(i,n) for(int i=1;i<=n;i++)
#define INF 1e9
using namespace std;
struct cmp {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};
int v, e, start, dist[20001];
vector<vector<pii> > vec;
priority_queue<pii, vector<pii>, cmp> pq;
void dijkstra(int start) {
	pq.push({ start, 0 });
	dist[start] = 0;
	while (!pq.empty()) {
		int now_v = pq.top().first;
		int now_w = pq.top().second;
		pq.pop();
		for (pii next : vec[now_v]) {
			int next_v = next.first;
			int next_w = now_w + next.second;
			if (next_w < dist[next_v]) {
				dist[next_v] = next_w;
				pq.push({ next_v, next_w });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e >> start;
	vec.resize(v+1);
	rep(i, v)
		dist[i] = INF;
	rep(i, e) {
		int a, b, w;
		cin >> a >> b >> w;
		vec[a].push_back({ b,w });
	}

	dijkstra(start);
	rep(i, v) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}