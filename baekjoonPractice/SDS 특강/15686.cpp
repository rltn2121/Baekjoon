#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, arr[50][50], chick_cnt, ans = 987654321;
/*
0: 빈 칸
1: 집
2: 치킨집
*/
int getDistance(int hx, int hy, int cx, int cy) {
	return abs(hx - cx) + abs(hy - cy);
}


void dfs(int x, int y, int cnt) {
	if (cnt == m) {
		int total_dist = 0;
		// 집 찾았으면
		rep(i, n) {
			rep(j, n) {
				if (arr[i][j] == 1) {
					// 모든 치킨집과 비교하기
					int min_dist = 987654321;
					rep(a, n) {
						rep(b, n) {
							if (arr[a][b] == 2)
								min_dist = min(min_dist, getDistance(i, j, a, b));
						}
					}
					total_dist += min_dist;
				}
			}
		}
		ans = min(ans, total_dist);
		return;
	}

	for (int i = x; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 2) {
				arr[i][j] = 0;
				dfs(i, j, cnt-1);
				arr[i][j] = 2;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				chick_cnt++;
		}
	}

	dfs(0,0,chick_cnt);
	cout << ans;
}