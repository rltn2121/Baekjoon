#include <iostream>
#include <cstring>
#define mid (s+e)/2
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m, arr[1000001];
int tree[4000001];
int init(int root, int s, int e) {
	if (s == e) return tree[root] = arr[s];
	return tree[root] = init(root * 2, s, mid) * init(root * 2 + 1, mid + 1, e);
}
int update(int root, int s, int e, int idx, int val) {
	if (idx < s || e < idx) return tree[root];
	if (idx == s && e == idx) return tree[root] = val;
	return tree[root] = update(root * 2, s, mid, idx, val) * update(root * 2 + 1, mid + 1, e, idx, val);
}
int query(int root, int s, int e, int l, int r) {
	if (r < s || e < l) return 1;
	if (l <= s && e <= r) return tree[root];
	return query(root * 2, s, mid, l, r) * query(root * 2 + 1, mid + 1, e, l, r);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> m) {
		memset(tree, 0, sizeof(tree));
		memset(arr, 0, sizeof(arr));
		rep(i, n) {
			int x;
			cin >> x;
			if (x < 0) arr[i] = -1;
			else if (x > 0) arr[i] = 1;
			else arr[i] = 0;
		}
		init(1,1,n);
		string str = "";
		rep(i, m) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'C') {
				if (b < 0) b = -1;
				else if (b > 0) b = 1;
				else b = 0;
				update(1, 1, n, a, b);
			}
			else {
				int res = query(1, 1, n, a, b);
				if (res < 0) str+='-';
				else if (res > 0) str += '+';
				else str += '0';
			}
		}
		cout << str << '\n';
	}
}