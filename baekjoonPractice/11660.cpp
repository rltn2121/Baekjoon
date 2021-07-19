#include <iostream>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m, a, b, c, d, arr[1025][1025], x;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			cin >> x;
			arr[i][j] = x+arr[i-1][j] + arr[i][j-1]-arr[i-1][j-1];
		}
	}
	rep(i, m) {
		cin >> a >> b >> c >> d;
		cout << arr[c][d] - arr[c][b - 1] - arr[a - 1][d] + arr[a - 1][b - 1] << '\n';
	}
}