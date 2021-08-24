#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, arr[501][501], ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		rep(j, i)
			cin >> arr[i][j];
	}

	rep(i, n) {
		rep(j, i) {
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
			ans = max(ans, arr[i][j]);
		}
	}
	cout << ans;
}