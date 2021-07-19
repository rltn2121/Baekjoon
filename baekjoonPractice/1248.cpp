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
	// ���
	if (cnt > n) {
		for (int i = 1; i <= n; i++)
			cout << arr[i][i] << ' ';
		exit(0);
	}

	// 1���� n���� ���ڸ� ��� �� �� ������ �˻�, ����ϸ� �ð� �ʰ�
	// �� ���� �߰��� ������ �˻�, �ش� ���� ��� ���ϸ� �� ���� ������ �ƿ� �˻� ����
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