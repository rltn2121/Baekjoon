#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m;
int arr[1000001], parent[1000001];


int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void unionSet(int a, int b) {
	if (a == b) return;
	int x = find(a);
	int y = find(b);
	
	if (x > y)
		parent[x] = parent[y];
	else
		parent[y] = parent[x];

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i, n) {
		arr[i] = i;
		parent[i] = arr[i];
	}

	rep(i, m) {
		int a, b,c;
		cin >> a >> b >> c;
		if (a == 0)
			unionSet(b, c);
		else
			cout << (find(b) == find(c) ? "YES" : "NO") << '\n';

	}
}