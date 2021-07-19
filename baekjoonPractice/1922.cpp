#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m, visited[1001], ans;
vector<vector<pii> > v;
struct cmp {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};
priority_queue<pii, vector<pii>, cmp> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	pq.push({ 1,0 });
	while (!pq.empty()) {
		int dst = pq.top().first;
		int weight = pq.top().second;
		pq.pop();

		if (visited[dst]) continue;
		visited[dst] = 1;
		ans += weight;
		for (pii p : v[dst]) {
			pq.push(p);
		}
	}
	cout << ans;
}