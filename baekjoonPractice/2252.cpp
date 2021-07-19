#include <iostream>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m;
vector<vector<int> > v;
queue<int> q;
int in[32001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		in[b]++;
	}

	// in-degree�� 0�� ��� ����
	rep(i, n) {
		if (in[i] == 0) {
			q.push(i);
			cout << i << ' ';
		}
	}

	// queue�� �ִ� ���� ����� ���� ����
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i : v[now]) {
			if (--in[i] == 0) {
				cout << i << ' ';
				q.push(i);
			}
		}
	}
}