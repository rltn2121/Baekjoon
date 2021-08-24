#include <iostream>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pii pair<int, int>
using namespace std;
struct cmp {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};
vector<vector<pii> > vec;
priority_queue<pii, vector<pii>, cmp> pq;
int v, e, ans;
bool visited[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;
	vec.resize(v + 1);
	rep(i, e) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	pq.push({ 1,0 });
	while (!pq.empty()) {
		pii now = pq.top(); pq.pop();
		int dst = now.first;
		if (visited[dst]) continue;
		visited[dst] = 1;
		ans += now.second;
		for (pii p : vec[dst]) {
			if(!visited[p.first])
				pq.push(p);
		}

	}
	cout << ans;
}