#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mid (s+e)/2
using namespace std;
int n, m, arr[100001], tree[100001 * 4 + 1];
int init(int root, int s, int e) {
	if (s == e) return tree[root] = arr[s];
	return tree[root] = min(init(root * 2, s, mid), init(root * 2 + 1, mid + 1, e));
}

int query(int root, int s, int e, int l, int r) {
	if (r < s || e < l) return 1e9 + 1;
	if (l <= s && e <= r) return tree[root];
	return min(query(root * 2, s, mid, l, r), query(root * 2 + 1, mid + 1, e, l, r));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i, n)
		cin >> arr[i];

	init(1, 1, n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		cout << query(1, 1, n, a, b) << '\n';
	}
}