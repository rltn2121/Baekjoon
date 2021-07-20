#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;i++)
#define INF 1e9
using namespace std;
struct Node {
	int v, w;
};
struct Ans {
	int city = -1;
	int dist = INF;
};
struct cmp {
	bool operator()(Node a, Node b) {
		return a.w > b.w;
	}
};
vector<vector<Node> > vec;
int v, m, start_a, start_b, dist1[101], dist2[101];
priority_queue<Node, vector<Node>, cmp> pq;
void dijk(int start, int* dist) {
	pq.push({ start, 0 });
	dist[start] = 0;
	while (!pq.empty()) {
		Node now = pq.top(); pq.pop();
		int now_v = now.v;
		int now_w = now.w;
		for (Node next : vec[now_v]) {
			int next_v = next.v;
			int next_w = now_w + next.w;
			if (dist[next_v] > next_w) {
				dist[next_v] = next_w;
				pq.push({ next_v, next_w });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> m;
	vec.resize(v + 1);
	rep(i, v) {
		dist1[i] = INF;
		dist2[i] = INF;
	}
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	cin >> start_a >> start_b;
	dijk(start_a, dist1);
	dijk(start_b, dist2);

	
	int min_dist = 1e9;
	rep(i, v) {
		if (dist1[i] == 0 || dist2[i] == 0) continue;
		min_dist = min(min_dist, dist1[i] + dist2[i]);
	}

	Ans ans;
	rep(i, v) {
		// 1. 시작 위치 x
		if (i == start_a || i == start_b) continue;
		
		// 2. 최단 시간의 합이 최소
		if (dist1[i] + dist2[i] == min_dist) {

			// 3. 지헌이가 늦게 도착하면 안됨
			if (dist1[i] > dist2[i]) continue;


			// 지헌 최단거리 같으면
			if (ans.dist == dist1[i]) {
				
				// 도시번호가 더 작으면
				if (i < ans.city)
					ans.city = i;
			}
			else if(ans.dist > dist1[i]){
				ans.dist = dist1[i];
				ans.city = i;
			}
		}
	}
	cout << ans.city;
}