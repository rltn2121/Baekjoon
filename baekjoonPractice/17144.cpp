#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int r, c, t, arr[50][50], temp[50][50];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int cleaner1, cleaner2;
void spread() {
	rep(i, r) {
		rep(j, c) {
			int cnt = 0;
			rep(k, 4) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx<0 || nx >=r || ny < 0 || ny >= c || arr[nx][ny] == -1) continue;
				temp[nx][ny] += (arr[i][j] / 5);
				cnt++;
			}
			arr[i][j] -= ((arr[i][j] / 5) * cnt);
		}
	}
	rep(i, r) {
		rep(j, c) {
			arr[i][j] += temp[i][j];
			temp[i][j] = 0;
		}
	}
}
void rot1() {
	for (int i = cleaner1-1; i >= 1; i--) 
		arr[i][0] = arr[i-1][0];
	
	for (int i = 0; i <= c-2; i++) 
		arr[0][i] = arr[0][i + 1];
	
	for (int i = 0; i <= cleaner1-1; i++)
		arr[i][c - 1] = arr[i + 1][c - 1];

	for (int i = c - 1; i >= 2; i--)
		arr[cleaner1][i] = arr[cleaner1][i - 1];

	arr[cleaner1][1] = 0;
}
void rot2() {
	for (int i = cleaner2 + 1; i <= r - 2; i++)
		arr[i][0] = arr[i + 1][0];

	for (int i = 0; i <= c - 2; i++)
		arr[r-1][i] = arr[r-1][i + 1];

	for (int i = r - 1; i >= cleaner2 + 1; i--)
		arr[i][c-1] = arr[i - 1][c-1];

	for (int i = c-1; i >= 2; i--)
		arr[cleaner2][i] = arr[cleaner2][i - 1];

	arr[cleaner2][1] = 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> t;
	rep(i, r) {
		rep(j, c) {
			int x;
			cin >> x;
			arr[i][j] = x;
			if (x == -1) {
				if (!cleaner1)
					cleaner1 = i;
				else
					cleaner2 = i;
			}
		}
	}
	while (t--) {
		spread();
		rot1();
		rot2();
	}
	int ans = 0;
	rep(i, r) {
		rep(j, c) {
			if (arr[i][j] == -1) continue;
			ans += arr[i][j];
		}
	}
	cout << ans;
}