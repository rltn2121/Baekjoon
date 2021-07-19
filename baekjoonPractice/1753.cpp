#include <iostream>
#include <vector>
#include <queue>
#define rep(i,n) for(int i = 1; i<=n;i++)
#define pii pair<int, int>
#define MAX 987654321
using namespace std;
struct cmp {
	bool operator()(const pii& a, const pii& b) {
		return a.second > b.second;
	}
};
vector<vector<pii> > vec;					// 그래프 저장용
priority_queue<pii, vector<pii>, cmp> pq;	// 간선 저장용 (가중치 오름차순 정렬)
int v, e, k, a, b, w, dist[20001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> k;
	vec.resize(v + 1);

	// 그래프 저장
	rep(i, e) {
		cin >> a >> b >> w;
		vec[a].push_back({ b, w });
	}

	// 거리 (or 비용 or 가중치) 초기화
	rep(i, v)
		dist[i] = MAX;
		
	// 시작점
	pq.push({ k, 0 });
	dist[k] = 0;
	while (!pq.empty()) {
		int now_v = pq.top().first;
		int now_w = pq.top().second;
		pq.pop();

		// 이미 최단 경로를 찾았으면 넘어가기
		//if (dist[now_v] < now_w) continue;

		// 연결된 정점 탐색
		for (auto i : vec[now_v]) {
			int next_v = i.first;
			int next_w = i.second + now_w;
			if (dist[next_v] > next_w) {		// 이전에 찾아놨던 next로 가는 비용 vs 현재 위치에서 next로 가는 비용
				pq.push({ next_v, next_w });
				dist[next_v] = next_w;			// 최단 거리 갱신
			}
		}
	}
	// 출력
	rep(i, v) {
		if (dist[i] == MAX)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}
