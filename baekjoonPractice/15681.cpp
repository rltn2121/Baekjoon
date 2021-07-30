#include <iostream>
#include <vector>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
vector<vector<int> > v;
int n, r, q, a, b,x, child[100001], visited[100001];
void input();
void print();
int func(int r) {
	for (int next : v[r]) {
		if (!visited[next]) {
			visited[next] = 1;
			child[r]+=func(next);
		}
	}
	return child[r] + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	func(r);
	print();
}
void input() {
	cin >> n >> r >> q;
	v.resize(n + 1);
	rep(i, n - 1) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[r] = 1;
}
void print() {
	rep(i, q) {
		cin >> x;
		cout << child[x] + 1 << '\n';
	}
}