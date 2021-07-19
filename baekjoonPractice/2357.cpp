#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mid (s+e)/2
using namespace std;
int n, m, arr[100001], max_tree[100001*4+1], min_tree[100001*4+1];
int max_init(int root, int s, int e) {
	if (s == e) return max_tree[root] = arr[s];
	return max_tree[root] = max(max_init(root * 2, s, mid), max_init(root * 2 + 1, mid + 1, e));
}

int min_init(int root, int s, int e) {
	if (s == e) return min_tree[root] = arr[s];
	return min_tree[root] = min(min_init(root * 2, s, mid), min_init(root * 2 + 1, mid + 1, e));
}

int max_query(int root, int s, int e, int l, int r) {
	if (r < s || e < l) return -1;
	if (l <= s && e <= r) return max_tree[root];
	return max(max_query(root * 2, s, mid, l, r), max_query(root * 2 + 1, mid + 1, e, l, r));
}
int min_query(int root, int s, int e, int l, int r) {
	if (r < s || e < l) return 1e9+1;
	if (l <= s && e <= r) return min_tree[root];
	return min(min_query(root * 2, s, mid, l, r), min_query(root * 2 + 1, mid + 1, e, l, r));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i, n)
		cin >> arr[i];
	max_init(1, 1, n);
	min_init(1, 1, n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		cout << min_query(1, 1, n, a, b) << ' ' << max_query(1, 1, n, a, b) << '\n';
	}
}