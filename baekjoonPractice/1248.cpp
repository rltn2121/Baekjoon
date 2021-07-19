#include <iostream>
#include <string>
using namespace std;
int n;
char s[11][11];
int sum[11];
int arr[11][11];
string str;
bool valid(int col) {
	if (col == 1)
		return true;
	for (int row = 1; row <= col; row++) {
		int cur = arr[col][col] + arr[row][col - 1];
		if (s[row][col] == '+' && cur <= 0)
			return false;
		else if (s[row][col] == '-' && cur >= 0)
			return false;
		else if (s[row][col] == '0' && cur != 0)
			return false;
		arr[row][col] = cur;
	}
	return true;
}
void dfs(int cnt) {
	// 출력
	if (cnt > n) {
		for (int i = 1; i <= n; i++)
			cout << arr[i][i] << ' ';
		exit(0);
	}

	// 1부터 n까지 숫자를 모두 다 고른 다음에 검사, 출력하면 시간 초과
	// 한 라인 추가할 때마다 검사, 해당 라인 통과 못하면 그 다음 라인은 아예 검사 안함
	char now = s[cnt][cnt];
	if (now == '+') {
		for (int i = 1; i <= 10; i++) {
			arr[cnt][cnt] = i;
			if(valid(cnt))
				dfs(cnt + 1);
		}
	}
	else if (now == '-') {
		for (int i = 1; i <= 10; i++) {
			arr[cnt][cnt] = -i;
			if (valid(cnt))
				dfs(cnt + 1);
		}
	}
	else if (now == '0') {
		arr[cnt][cnt] = 0;
		if (valid(cnt))
			dfs(cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++)
			cin >> s[i][j];
	}
	dfs(1);
}