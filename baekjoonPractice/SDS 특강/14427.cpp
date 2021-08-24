// https://www.acmicpc.net/source/30982730
// https://kyu9341.github.io/algorithm/2020/04/04/algorithm14427/
#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mid (s+e)/2
#define pii pair<int, int>
using namespace std;
int n, m;
pii tree[400001], arr[100001];
int min_idx = 1e9;
pii init(int root, int s, int e) {
	if (s == e) {
		tree[root] = { arr[s].first, arr[s].second };
		return tree[root];
	}
	
	pii lv = init(root * 2, s, mid);
	pii rv = init(root * 2 + 1, mid + 1, e);
	if (lv.second < rv.second)
		tree[root] = lv;
	else if(lv.second > rv.second)
		tree[root] = rv;
	else {
		if (lv.first < rv.first)
			tree[root] = lv;
		else
			tree[root] = rv;
	}
	return tree[root];
}

pii update(int root, int s, int e, int idx, int val) {
	if (idx < s||e < idx) return tree[root];
	if (s == e) return tree[root] = { tree[root].first, val };

	pii lv = update(root * 2, s, mid, idx, val);
	pii rv = update(root * 2 + 1, mid + 1, e, idx, val);

	if (lv.second < rv.second)
		tree[root] = lv;
	else if (lv.second > rv.second)
		tree[root] = rv;
	else {
		if (lv.first < rv.first)
			tree[root] = lv;
		else
			tree[root] = rv;
	}
	return tree[root];
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		int x;
		cin >> x;
		arr[i] = { i, x };
	}
		
	init(1,1,n);

	cin >> m;
	rep(i, m) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, 1, n, b,c);
		}
		else cout << (tree[1].first) << '\n';
	}
}