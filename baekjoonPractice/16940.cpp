#include <iostream>
#include <queue>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
queue<int> q;
vector<vector<int> > v;
bool visited[100001];
int n, a, b, arr[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n + 1);
	rep(i, n - 1) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	rep(i, n)
		cin >> arr[i];

	if (arr[0] != 1) {
		cout << 0;
		exit(0);
	}
	int idx = 1;
	visited[1] = 1;
	q.push(1);
	int cnt = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cnt = 0;					// 연결된 자식 노드 수
		for (int next : v[now]) {
			if (!visited[next]) {
				visited[next] = 1;	// 방문 처리
				cnt++;
			}
		}
		for (int i = idx; i < idx + cnt; i++) {
			if (!visited[arr[i]]) {	// 순서대로 방문하지 않았으면
				cout << 0;
				exit(0);
			}
			q.push(arr[i]);			// 순서대로 큐에 삽입
		}
		idx += cnt;
	}
	cout << 1;
}
