#include <iostream>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m, sum[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i, n) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}
}