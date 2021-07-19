#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, l, cnt = 0, arr[200][100];
bool flag;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l;
	rep(i, n) {
		rep(j, n)
			cin >> arr[i][j];
	}

	// 세로를 가로로 채워넣기
	rep(i, n) {
		rep(j, n)
			arr[n + i][j] = arr[j][i];
	}
	rep(i, 2*n) {
		flag = true;
		int a = 0;										// 탐색을 위한 투포인터
		int b = 1;
		while (b < n) {
			if (abs(arr[i][a] - arr[i][b]) > 1) {		// 1. 차이가 1 이상 -> 즉시 종료
				flag = false;
				break;
			}

			if (arr[i][a] == arr[i][b]) {				// 2. 높이가 같음 -> 포인터 이동
				a++;
				b++;
			}

			else if (arr[i][a] > arr[i][b]) {			// 높은 곳 -> 낮은 곳 (3 -> 2) : b를 l만큼 오른쪽으로 이동
				int j;
				for (j = b; j < b + l; j++) {			// 1. b를 오른쪽으로 l만큼 이동시킬 수 있는지 확인 
					if (j == n)							//   1) 이동 중에 배열 끝에 도착 -> 불가
						break;							
					if (arr[i][j] != arr[i][a] - 1)		//   2) 이동 중에 높이가 달라짐  -> 불가
						break;
				}
				if (j != b + l) {						// 2. b가 l만큼 이동했는지 확인 (경사로 놓을 공간 확보했는 지)
					flag = false;						//   1) 이동 못함: 현재 행 탐색 종료. 다음 행 탐색
					break;
				}

				a = b + l - 1;							//   2) 이동함: 포인터를 경사로 끝 지점으로 이동

				for (j = a + 1; j <= a + l; j++) {		// 3. (경사로 끝 지점 ~ 경사로 끝 지점 + l) 사이에 올라가는 구간이 있는지 검사
					if (j == n)								// 배열 끝에 도착 : break
						break;								
					if (arr[i][j] > arr[i][a]) {			// 높이 올라감 : 불가
						flag = false;						
						break;
					}
				}
				if (!flag)									// 단순히 해당 구간에 올라가는 구간이 있는지만 검사하는 것이므로
					break;									// 올라가는 구간이 나오기 전에 배열 끝에 도달해서 종료했다면 (j = a + l = n)
															// break 안해도 됨
				b = a + 1;
			}

			else if (arr[i][a] < arr[i][b]) {			// 낮은 곳 -> 높은 곳 (2 -> 3) : a를 l만큼 왼쪽으로 이동
				int j;
				for (j = a; j > a - l; j--) {			// 1. a를 왼쪽으로 l만큼 이동시킬 수 있는지 확인
					if (j < 0)							//   1) 이동 중에 배열 끝에 도착 -> 불가
						break;
					if (arr[i][j] != arr[i][b] - 1)		//   2) 이동 중에 높이가 달라짐  -> 불가
						break;
				}
				if (j != a - l) {						// 2. a가 l만큼 이동했는지 확인 (경사로 놓을 공간 확보했는 지)
					flag = false;						//   1) 이동 못함: 현재 행 탐색 종료. 다음 행 탐색
					break;								
				}
				a = b;									//   2) 이동함: 포인터 이동 후 계속 탐색
				b = a + 1;
			}
		}
		if (flag) cnt++;
	}
	cout << cnt;
}
