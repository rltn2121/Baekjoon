#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, arr[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		rep(j, n) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				arr[i][j] = 1e9;
		}
	}

	rep(i, n) {
		rep(j, n) {
			rep(k, n) {
				if (arr[j][i] == 1e9 || arr[i][k] == 1e9) continue;
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
	
	rep(i, n) {
		rep(j, n)
			cout << (arr[i][j] == 1e9? 0:1) << ' ';
		cout << '\n';
	}
}