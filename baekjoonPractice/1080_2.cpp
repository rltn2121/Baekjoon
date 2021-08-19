#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, ans;
char A[51][51], B[51][51];
bool check[51][51];
void input();
void change(int x, int y) {
	if (x + 2 >= n || y + 2 >= m) return;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++)
			check[i][j] = 1 - check[i][j];
	}
	ans++;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	rep(i, n) {
		rep(j, m) 
			if (A[i][j] == B[i][j]) check[i][j] = 1;
	}

	rep(i, n) {
		rep(j, m) 
			if (!check[i][j]) change(i, j);
	}

	
	rep(i, n) {
		rep(j, m)
			if (!check[i][j]) {
				cout << -1;
				return 0;
			}
	}
	cout << ans;
}
void input() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, m)
			cin >> A[i][j];
	}
	rep(i, n) {
		rep(j, m)
			cin >> B[i][j];
	}
}