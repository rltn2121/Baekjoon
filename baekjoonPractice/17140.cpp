#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define pii pair<int, int>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int r, c, k, cnt, arr[101][101];
int row_max = 3, col_max = 3;
map<int, int> m;
bool cmp(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
void func() {
	// 1. 행 개수 >= 열 개수
	// -> 행 정렬
	if (col_max >= row_max) {
		rep(i, 100) {
			m.clear();
			//if (arr[i][1] == 0) continue;
			rep(j, 100) {
				int now = arr[i][j];
				if (now == 0) continue;
				m[now]++;

				
			}
			vector<pair<int, int> > v(m.begin(), m.end());
			sort(v.begin(), v.end(), cmp);
			

			rep(j, 100)
				arr[i][j] = 0;
			int idx = 1;
			for (pii p : v) {
				if (p.second == 0) continue;
				arr[i][idx++] = p.first;
				arr[i][idx++] = p.second;
			}
			row_max = max(row_max, idx-1);
		}
	}
	// 2. 행 개수 < 열 개수
	// -> 열 정렬
	else {
		rep(i, 100) {
			m.clear();
			//if (arr[1][i] == 0) continue;
			rep(j, 100) {
				int now = arr[j][i];
				if (now == 0) continue;
				m[now]++;

			}
			vector<pair<int, int> > v(m.begin(), m.end());
			sort(v.begin(), v.end(), cmp);
		
			rep(j, 100)
				arr[j][i] = 0;
			int idx = 1;
			for (pii p : v) {
				if (p.second == 0) continue;
				arr[idx++][i] = p.first;
				arr[idx++][i] = p.second;
			}
			col_max = max(col_max, idx-1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> k;
	rep(i, 3) {
		rep(j, 3)
			cin >> arr[i][j];
	}

	while (true) {
		if (cnt > 100) {
			cnt = -1;
			break;
		}
		if (arr[r][c] == k)
			break;
		func();
		cnt++;
	}

	cout << cnt;
}