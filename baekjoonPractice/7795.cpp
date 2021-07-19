#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
vector<int> a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,m,cnt;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> m;
		a.resize(n);	
		b.resize(m);
		rep(i, n)
			cin >> a[i];
		rep(i, m)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		rep(i, n) {
			auto lb = lower_bound(b.begin(), b.end(), a[i]);
			for (auto it = b.begin(); it < lb; it++)
				cnt++;
		}
		cout << cnt << '\n';
	}
}