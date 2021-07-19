#include <iostream>
#include <algorithm>
using namespace std;
int n, m, h;
int arr[31][11];
int min_cnt = 987654321;
bool chk() {
	// 마지막 가로줄에 도착했을 때 출발번호와 도착번호 같은지 확인
	for (int i = 1; i <= n; i++) {		// 모든 세로줄 검사
		int current_col = i;			// 현재 세로줄 위치 저장, 가로줄 만나면 변함
		for (int j = 1; j <= h; j++) {	// 모든 가로줄 검사
			if (arr[j][current_col]==1)	// 현재 위치에 사다리가 있으면 그거 타고 오른쪽으로 이동
				current_col++;
			else if (arr[j][current_col - 1]==1)	// 현재 위치의 왼쪽에 사다리 있으면 그거 타고 왼쪽으로 이동
				current_col--;
		}

		// 출발번호 도착번호 다르면
		if (current_col != i)
			return false;
	}
	return true;
}
void dfs(int row, int col, int cnt) {
	// cnt가 3보다 크거나 현재 최솟값보다 크거나 같으면 return (더 이상 볼 필요 없음)
	if (cnt > 3 || cnt >= min_cnt) return;
	if (chk()) {
		min_cnt = min(cnt, min_cnt);
		return;
	}
	
	for(int i = row; i<=h; i++) {	// 모든 가로줄 검사
		col = 1;					// 다음 가로줄 검사할 때 첫 번째 세로줄부터 검사
		for(int j=col; j<n; j++) {	// 모든 세로줄 검사 (마지막 세로줄은 오른쪽 검사 안함)
			if (arr[i][j]==0) {		// 현재 위치에 사다리 없으면
				if (arr[i][j - 1] == 0 && arr[i][j + 1] == 0) {   // 현재 위치 양 옆에 가로줄이 없어야 함
					arr[i][j] = 1;
					dfs(i, j, cnt + 1);
					arr[i][j] = 0;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> h;
	for (int i = 1;i <= m;i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	dfs(1, 1, 0);

	cout << (min_cnt == 987654321 ? -1 : min_cnt);
}