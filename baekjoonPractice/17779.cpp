#include <iostream>
#include <algorithm>
#include <cstring>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, arr[21][21], area[6], border[21][21];
int max_val, min_val, ans = 1e9, total;
void input();
void init();
bool isValidArea(int x, int y, int d1, int d2);	// 범위 검사
void getArea(int x, int y, int d1, int d2);		// 범위 계산

// 1. (x, y), d1, d2 정하기
// 2. 구역 별 인구수 계산
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();

	for (int x = 1; x <= n;x++) {
		for (int y = 1; y <= n;y++) {
			for (int d1 = 1; d1 < n; d1++) {
				for (int d2 = 1;d2 < n;d2++) {
					init();
					if (isValidArea(x, y, d1, d2)) {
						getArea(x, y, d1, d2);
						ans = min(ans, max_val - min_val);
					}
				}
			}
		}
	}
	cout << ans;
}
bool isValidArea(int x, int y, int d1, int d2) {
	if (x<1 || x>n || y<1 || y>n) return 0;	//	상: (x,y)
	if (x + d1 + d2<1 || x + d1 + d2>n || y - d1 + d2<1 || y - d1 + d2>n) return 0;	//	하: (x+d1+d2, y-d1+d2)
	if (x + d1<1 || x + d1>n || y - d1<1 || y - d1>n) return 0;	//	좌: (x+d1, y-d1)
	if (x + d2<1 || x + d2>n || y + d2<1 || y + d2>n) return 0;	//	우: (x+d2, y+d2)
	return 1;
}
// 범위 계산
void getArea(int x, int y, int d1, int d2) {
	// 5구역 경계 설정
	for (int i = 0; i <= d1; i++) {
		border[x + i][y - i] = 5;			// 5-1 경계 (x, y), (x+1, y-1), ..., (x+d1, y-d1)
		border[x + d2 + i][y + d2 - i] = 5;	// 5-4 경계 (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
	}
	for (int i = 0; i <= d2; i++) {
		border[x + i][y + i] = 5;			// 5-2 경계 (x, y), (x+1, y+1), ..., (x+d2, y+d2)
		border[x + d1 + i][y - d1 + i] = 5; // 5-3 경계 (x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
	}

	// 1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
	for (int i = 1; i < x+d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (border[i][j] == 5) break;
			area[1] += arr[i][j];
		}
	}
	// 2번 선거구 : 1 ≤ r ≤ x + d2, y < c ≤ N
	for (int i = 1; i <= x + d2; i++) {
		for (int j = n; j > y; j--) {
			if (border[i][j] == 5) break;
			area[2] += arr[i][j];
		}
	}
	// 3번 선거구 : x + d1 ≤ r ≤ N, 1 ≤ c < y - d1 + d2
	for (int i = x+d1; i <= n; i++) {
		for (int j = 1; j < y-d1+d2; j++) {
			if (border[i][j] == 5) break;
			area[3] += arr[i][j];
		}
	}
	// 4번 선거구 : x + d2 < r ≤ N, y - d1 + d2 ≤ c ≤ N
	for (int i = x + d2+1; i <= n; i++) {
		for (int j = n; j >= y-d1+d2; j--) {
			if (border[i][j] == 5) break;
			area[4] += arr[i][j];
		}
	}
	// 5번 선거구
	area[5] = total;
	rep(i, 4)
		area[5] -= area[i];

	rep(i, 5) {
		max_val = max(max_val, area[i]);
		min_val = min(min_val, area[i]);
	}
}

void input() {
	cin >> n;
	rep(i, n) {
		rep(j, n) {
			cin >> arr[i][j];
			total += arr[i][j];
		}
	}
}
void init() {
	memset(area, 0, sizeof(area));
	memset(border, 0, sizeof(border));
	max_val = -1;
	min_val = 1e9;
}