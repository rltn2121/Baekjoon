#include <iostream>
#include <queue>
#include <vector>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pii pair<int, int>
#define MAX 987654321
using namespace std;
int n, m, src, dst, dist[1001];
struct cmp {
	bool operator()(const pii& a, const pii& b) {
		return a.second > b.second;
	}
};
vector<vector<pii> > vec;
priority_queue<pii, vector<pii>, cmp> pq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vec.resize(n + 1);
	// 1. 그래프 입력
	rep(i, m) {
		int a, b, w;
		cin >> a >> b >> w;
		vec[a].push_back({ b,w });
	}
	cin >> src >> dst;
	// 2. 비용 초기화
	rep(i, n)
		dist[i] = MAX;
	// 3. 시작
	pq.push({ src, 0 });
	while (!pq.empty()) {
		int now_v = pq.top().first;
		int now_w = pq.top().second;
		if (now_v == dst)		// 찾았으면 그만하기
			break;
		pq.pop();
		for (pii next : vec[now_v]) {
			int next_v = next.first;
			int next_w = next.second + now_w;
			if (dist[next_v] > next_w) {
				dist[next_v] = next_w;
				pq.push({ next_v, next_w });
			}
		}
	}
	cout << dist[dst];
}