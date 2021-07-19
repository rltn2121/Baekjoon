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
			if (arr[i][j] == 1) {										// 현재 위치가 가정집이면
				int tmp = 987654321;
				rep(a, n) {
					rep(b, n) {
						if (arr[a][b] == 2)								// 모든 치킨집과의 거리 계산
							tmp = min(tmp, abs(i - a) + abs(j - b));	// 최솟값 저장
						
					}
				}
				ret += tmp;									// 도시의 치킨 거리 += 현재 집의 치킨 거리
			}
		}
	}
	return ret;
}
void dfs(int x, int y, int now) {
	if (now == m) {					// m개만 남았으면 거리 체크
		ans = min(ans, chk());
		return;
	}

	for (int i = x; i <= n; i++) {
		y = 1;
		for (int j = y; j <= n; j++) {
			if (arr[i][j] == 2) {	// 치킨집 찾으면 0으로 변경
				arr[i][j] = 0;		// 폐업
				dfs(i, j, now - 1);	// 개수 1개 줄이고 계속 탐색
				arr[i][j] = 2;		// 다음 탐색을 위해 복구
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