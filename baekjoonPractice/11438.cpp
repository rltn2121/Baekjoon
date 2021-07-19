#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pii pair<int, int>
#define LIMIT 17
using namespace std;
vector<vector<int> > v;
int n, m, parent[LIMIT][100001], depth[100001];
bool visited[100001];
void bfs(int x) {
	queue<int> q;
	int d = 0;
	q.push(x);
	visited[x] = 1;
	parent[0][x] = -1;
	depth[x] = d;
	while (!q.empty()) {
		d++;
		int size = q.size();
		while (size--) {
			int now = q.front(); q.pop();
			for (int i : v[now]) {
				if (visited[i]) continue;
				q.push(i);
				visited[i] = 1;
				parent[0][i] = now;
				depth[i] = d;
			}
		}
	}
}

void initParent() {
	for(int i = 1; i<LIMIT; i++) {
		rep(j, n) {
			if(parent[i - 1][j] != -1)
				parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}

int getK(int x) {
	int n = 0;
	while ((x & (1 << n)) == 0)
		n++;
	return n;
}

int getMaxTwo(int depth_diff) {
	int temp = 1;
	while (temp * 2 <= depth_diff)
		temp *= 2;
	return temp;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.resize(n + 1);
	memset(parent, -1, sizeof(parent));
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(1);
	initParent();
	cin >> m;
	rep(idx, m) {
		int a, b, x, y;
		cin >> a >> b;
		if (depth[a] > depth[b]) {
			x = a;
			y = b;
		}
		else {
			x = b;
			y = a;
		}

		int depth_diff = depth[x] - depth[y];
		int temp = getMaxTwo(depth_diff);
		while (depth_diff > 0) {
			// 현재 2의 배수가 depth_diff보다 크면 continue;
			if (depth_diff < temp) {
				temp /= 2;
				continue;
			}

			// 2^k에서 k값 구함
			int k = getK(temp);

			x = parent[k][x];
			
			depth_diff -= temp;
			temp /= 2;
		}
		if (x == y) {
			cout << y << '\n'; 
			continue;
		}
		
		for (int j = LIMIT - 1; j >= 0; j--) {
			if (parent[j][x] != parent[j][y]) {
				x = parent[j][x];
				y = parent[j][y];
			}
		}
		
		cout << parent[0][x] << '\n';
	}
}