#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
vector<vector<int> > v;
int n, a, b;
int visited[3001];	// 0: not visited, 1: visited, 2: cycle
int dist[3001];		// ����Ŭ�κ����� �Ÿ�
int ret;
int dfs(int now, int before) {
	if (visited[now] == 1)	// ����Ŭ ã������
		return now;			// ���� ��� ����
	visited[now] = 1;		// �湮 ó��

	for (int next : v[now]) {			// ����� ��� Ž��
		if (next == before) continue;	// �ٷ� ������ ���ư��� �н�

		ret = dfs(next, now);			// ���� Ž��

		if (ret > 0) {				// ����Ŭ ������ ã������
			visited[now] = 2;		// ����Ŭ�� ���� ��Ŵ

			if (now == ret)			// ����Ŭ ���������� ���� -> �������� ����Ŭ�� ���� �ȵ�
				return -1;					//   -> -1 ����
			else 
				return ret;			// ����Ŭ ������
		}

		if (ret == -1)
			return -1;
	}
	return 0;		// ��ã������ 0 ����
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
		if (visited[i] == 2) {	// ����Ŭ�� ���Ե� ���
			dist[i] = 0;		// ����Ŭ���� �Ÿ��� 0
			q.push(i);
		}
		else
			dist[i] = -1;		// ����Ŭ�� ���� �ȵǸ� -1
	}

	while (!q.empty()) {	// bfs�� ����Ŭ���� �Ÿ��� ����
		int now = q.front();
		q.pop();
		for(int next : v[now]) {
			if (dist[next] == -1) {	// ���� ��尡 ����Ŭ�� ���ԵǾ����� �ʴٸ�
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}

	rep(i,n)
		cout << dist[i] << ' ';
}