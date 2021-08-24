#include <iostream>
#include <algorithm>
#include <cstring>
#define rep(i,n) for(int i=1;i<=n;i++)
#define INF 1e9
using namespace std;
int n, m,arr[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			if (i == j)
				arr[i][j] = -1;
			else
				arr[i][j] = INF;
		}
	}
	rep(i, m) {
		int a, b, w;
		cin >> a >> b >> w;
		arr[a][b] = min(arr[a][b], w);
	}

	rep(col, n) {
		rep(row, n) {
			int now = arr[row][col];
			if (now == INF || now == -1) continue;

			rep(i, n) {
				if (row == i || col == i) continue;
				arr[row][i] = min(arr[row][i], arr[row][col] + arr[col][i]);
			}
		}
	}

	rep(i, n) {
		rep(j, n) {
			if (arr[i][j] == INF || arr[i][j] == -1)
				cout << 0 << ' ';
			else
				cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}