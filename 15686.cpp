#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m, arr[51][51];
int cnt = 0, ans = 987654321;
/*
	도시의 치킨 거리 = 모든 집의 치킨 거리의 합
	치킨 거리 = 현재 집에서 가장 가까운 치킨집과의 거리
	m개 남기고 나머지 다 폐업
*/
int chk() {
	int ret = 0;
	rep(i, n) {
		rep(j, n) {
			if (arr[i][j] == 1) {
				int tmp = 987654321;
				rep(a, n) {
					rep(b, n) {
						if (arr[a][b] == 2) {
							tmp = min(tmp, abs(i - a) + abs(j - b));
						}
					}
				}
				ret += tmp;
			}
		}
	}
	return ret;
}
void dfs(int x, int y, int now) {
	if (now == m) {
		ans = min(ans, chk());
		return;
	}

	for (int i = x; i <= n; i++) {
		y = 1;
		for (int j = y; j <= n; j++) {
			if (arr[i][j] == 2) {
				arr[i][j] = 0;
				dfs(i, j, now - 1);
				arr[i][j] = 2;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				cnt++;
		}
	}
	dfs(1, 1, cnt);
	cout << ans;
}