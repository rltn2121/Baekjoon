#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
vector<vector<int> > v;
int n, a, b;
int visited[3001];	// 0: not visited, 1: visited, 2: cycle
int dist[3001];		// 사이클로부터의 거리
int ret;
int dfs(int now, int before) {
	if (visited[now] == 1)	// 사이클 찾았으면
		return now;			// 현재 노드 리턴
	visited[now] = 1;		// 방문 처리

	for (int next : v[now]) {			// 연결된 노드 탐색
		if (next == before) continue;	// 바로 전으로 돌아가면 패스

		ret = dfs(next, now);			// 다음 탐색

		if (ret > 0) {				// 사이클 시작점 찾았으면
			visited[now] = 2;		// 사이클에 포함 시킴

			if (now == ret)			// 사이클 시작점까지 도착 -> 나머지는 사이클에 포함 안됨
				return -1;					//   -> -1 리턴
			else 
				return ret;			// 사이클 시작점
		}

		if (ret == -1)
			return -1;
	}
	return 0;		// 못찾았으면 0 리턴
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n + 1);
	fill(dist, dist + n + 1, 987654321);

	rep(i, n) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1, -1);
	queue<int> q;
	rep(i,n) {
		if (visited[i] == 2) {	// 사이클에 포함된 경우
			dist[i] = 0;		// 사이클과의 거리는 0
			q.push(i);
		}
		else
			dist[i] = -1;		// 사이클에 포함 안되면 -1
	}

	while (!q.empty()) {	// bfs로 사이클과의 거리를 구함
		int now = q.front();
		q.pop();
		for(int next : v[now]) {
			if (dist[next] == -1) {	// 다음 노드가 사이클에 포함되어있지 않다면
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}

	rep(i,n)
		cout << dist[i] << ' ';
}