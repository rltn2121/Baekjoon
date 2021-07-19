#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, k, arr[201], cnt, ans;
int visited[201];
// 로봇이 움직이는 경우
// 1. 벨트가 움직일 때 같이 움직임
// 2. 벨트 회전한 후에 로봇이 스스로 움직임
void rotate() {
	int temp = arr[2 * n - 1];
	for (int i = 2 * n - 1; i > 0; i--) 
		arr[i] = arr[i-1];
	for (int i = n - 1; i > 0; i--)
		visited[i] = visited[i - 1];
	visited[0] = 0;
	arr[0] = temp;
 }
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	rep(i, 2 * n)
		cin >> arr[i];
	while (cnt < k) {
		ans++;
		// 1. 벨트 한 칸 회전
		rotate();
		// 2. 로봇 이동
		visited[n - 1] = 0;	// 제일 끝 로봇은 바닥으로
		for (int i = n - 2; i >= 0; i--) {
			if (visited[i] && !visited[i + 1] && arr[i + 1] > 0) {
				visited[i + 1] = 1;
				visited[i] = 0;
				arr[i + 1]--;
				if (arr[i + 1] == 0)
					cnt++;
			}
		}
		// 3. 올라가는 위치에 로봇 올리기
		if (!visited[0] && arr[0] > 0) {
			visited[0] = 1;
			arr[0]--;
			if (arr[0] == 0)
				cnt++;
		}
	}
	cout << ans;
}