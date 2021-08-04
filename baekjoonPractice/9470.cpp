#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
vector<vector<int> > v;
queue<int> q;
struct Node {
	int val;	// 들어오는 순서 중 최댓값
	bool dup;	// val의 중복 여부
};
int in_degree[1001], order[1001];
Node temp[1001];
int t, k, m, p, a, b;
void input();
void findZeroIndegree();
void topologySort() {
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : v[now]) {
			// 들어오는 값 중에서 최댓값 찾기
			// 1. 중복 (X)
			if (order[now] > temp[next].val) {
				temp[next].val = order[now];
				temp[next].dup = 0;
			}
			// 2. 중복 (O)
			else if (order[now] == temp[next].val) 
				temp[next].dup = 1;
			
			if (--in_degree[next] == 0) {
				// 들어오는 값 더 없으면 순서 갱신
				order[next] = temp[next].val + (temp[next].dup ? 1 : 0);
				q.push(next);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		input();
		findZeroIndegree();
		topologySort();
		cout << k << ' ' << order[m] << '\n';
	}
}
void input() {
	cin >> k >> m >> p;
	v.clear();
	v.resize(m + 1);
	memset(temp, 0, sizeof(temp));
	memset(order, 0, sizeof(order));
	memset(in_degree, 0, sizeof(in_degree));
	rep(i, p) {
		cin >> a >> b;
		v[a].push_back(b);
		in_degree[b]++;
	}
}
void findZeroIndegree() {
	rep(i, m) {
		if (in_degree[i] == 0) {
			q.push(i);
			order[i] = 1;
		}
	}
}