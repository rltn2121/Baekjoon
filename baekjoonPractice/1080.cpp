// https://mizzo-dev.tistory.com/entry/baekjoon1080
#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m;
char arr1[51][51], arr2[51][51];
bool chk[51][51];
int cnt;
void convert(int x, int y) {
	if (x + 2 >= n) return;
	if (y + 2 >= m) return;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) // 0, 1 토글
			chk[i][j] = !chk[i][j];
		
	}
	cnt++;
}
void func(){
	for (int i = 0;i < n; i++) {
		for (int j = 0;j < m;j++) {
			if (chk[i][j])		// A, B 다르면 -> chk[i][j] == 1
				convert(i, j);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	rep(i, n) {
		rep(j, m)
			cin >> arr1[i][j];
	}
	rep(i, n) {
		rep(j, m) {
			cin >> arr2[i][j];
			if (arr1[i][j] != arr2[i][j])	// A, B 다르면 1
				chk[i][j] = 1;
		}
	}
	func();
	rep(i, n) {
		rep(j, m) {
			if (chk[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;
}