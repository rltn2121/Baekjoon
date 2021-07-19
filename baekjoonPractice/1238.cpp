#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 987654321
#define pii pair<int, int>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m, x, ans, dist[1001], sum[1001];
struct cmp {
	bool operator()(const pii& a, const pii& b) {
		return a.second > b.second;
	}
};
vector<vector<pii> > vec;
vector<vector<pii> > vec_rev;
vector<vector<pii> > vec_copy;
priority_queue<pii, vector<pii>, cmp> pq;
void dijk(int start, int direction) {
	fill(dist, dist + n + 1, MAX);
	pq.push({ start,0 });
	dist[start] = 0;
	while (!pq.empty()) {
		int now_v = pq.top().first;
		int now_w = pq.top().second;
		pq.pop();

		if (direction)			// direction = 0 -> i���� x�� ã�ư���
			vec_copy = vec;		// direction = 1 -> x���� i�� ���ư���
		else
			vec_copy = vec_rev;

		for (pii next : vec_copy[now_v]) {
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
	cin >> n >> m >> x;
	vec.resize(n + 1);
	vec_rev.resize(n + 1);
	rep(i, m) {
		int a, b, w;
		cin >> a >> b >> w;
		vec[a].push_back({ b,w });
		vec_rev[b].push_back({ a,w });
	}

	// 1. i -> x (ã�ư���: ����� n�� ������ 1����
	//					   ����� 1�� ������ n���� ����)
	dijk(x, 0);
	rep(i, n)
		sum[i] += dist[i];

	// 2. x -> i (���ư���: ����� 1�� ������ n��)
	dijk(x, 1);
	rep(i, n)
		sum[i] += dist[i];


	rep(i, n)
		ans = max(ans, sum[i]);
	cout << ans;
}