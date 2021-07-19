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
vector<vector<pii> > vec;					// �׷��� �����
priority_queue<pii, vector<pii>, cmp> pq;	// ���� ����� (����ġ �������� ����)
int v, e, k, a, b, w, dist[20001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> k;
	vec.resize(v + 1);

	// �׷��� ����
	rep(i, e) {
		cin >> a >> b >> w;
		vec[a].push_back({ b, w });
	}

	// �Ÿ� (or ��� or ����ġ) �ʱ�ȭ
	rep(i, v)
		dist[i] = MAX;
		
	// ������
	pq.push({ k, 0 });
	dist[k] = 0;
	while (!pq.empty()) {
		int now_v = pq.top().first;
		int now_w = pq.top().second;
		pq.pop();

		// �̹� �ִ� ��θ� ã������ �Ѿ��
		//if (dist[now_v] < now_w) continue;

		// ����� ���� Ž��
		for (auto i : vec[now_v]) {
			int next_v = i.first;
			int next_w = i.second + now_w;
			if (dist[next_v] > next_w) {		// ������ ã�Ƴ��� next�� ���� ��� vs ���� ��ġ���� next�� ���� ���
				pq.push({ next_v, next_w });
				dist[next_v] = next_w;			// �ִ� �Ÿ� ����
			}
		}
	}
	// ���
	rep(i, v) {
		if (dist[i] == MAX)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}
