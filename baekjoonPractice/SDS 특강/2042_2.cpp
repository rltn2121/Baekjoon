#include <iostream>
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
using namespace std;
int n, m, k, OFFSET = 1;
ll arr[1<<22];

void init() {
	for (int i = OFFSET-1; i > 0; i--)
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
}
void update(int node, ll num) {
	node = node + OFFSET - 1;

	arr[node] = num;
	node /= 2;
	while (node > 0) {
		arr[node] = arr[node * 2] + arr[node * 2 + 1];
		node /= 2;
	}
}

ll query(int s, int e) {
	ll ret = 0;
	s = s + OFFSET - 1;
	e = e + OFFSET - 1;

	while (s <= e) {
		if (s % 2 == 1) ret += arr[s];
		if (e % 2 == 0) ret += arr[e];
		
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}

	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	while (OFFSET < n)
		OFFSET *= 2;

	rep(i, n)
		cin >> arr[i + OFFSET-1];
	init();
	rep(i, m + k) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(b, c) << '\n';
	}
}