#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n;
char arr[51][51];
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int chk(int i, int j) {
	int hor = 0, ver = 0, x, y;
	char c = arr[i][j];
	// ���� Ȯ��
	// ��
	x = i;
	y = j;
	while (y - 1 >= 0 && arr[x][y - 1] == c) {
		hor++;
		y--;
	}
	// ��
	x = i;
	y = j;while (y + 1 < n && arr[x][y + 1] == c) {
		hor++;
		y++;
	}
	//���� Ȯ��
	// ��
	x = i;
	y = j;while (x - 1 >= 0 && arr[x-1][y] == c) {
		ver++;
		x--;
	}
	// ��
	x = i;
	y = j;
	while (x + 1 < n  && arr[x+1][y] == c) {
		ver++;
		x++;
	}
	return max(hor, ver);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n) {
		rep(j, n)
			cin >> arr[i][j];
	}
	int ans = -1, ret;
	rep(i, n) {
		rep(j, n) {
			if (j + 1 < n) {
				swap(arr[i][j], arr[i][j + 1]);
				ret = chk(i, j);
				ans = max(ans, ret);
				ret = chk(i, j+1);
				ans = max(ans, ret);
				swap(arr[i][j], arr[i][j + 1]);	// roll back
			}
			if (i + 1 < n) {
				swap(arr[i][j], arr[i + 1][j]);
				ret = chk(i, j);
				ans = max(ans, ret);
				ret = chk(i+1, j);
				ans = max(ans, ret);
				swap(arr[i][j], arr[i + 1][j]);	// roll back
			}
		}
	}
	cout << ans + 1;
}