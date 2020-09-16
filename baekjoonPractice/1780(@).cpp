#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[2200][2200];
int cnt_arr[3];
bool check(int r, int c, int s) {
	for (int i = r; i < r + s; i++)
		for (int j = c; j < c + s; j++)
			if (arr[i][j] != arr[r][c])
				return false;
	return true;
}
void divide(int row, int col, int size) {
	int nextSize = size / 3;
	if (check(row, col, size))
		cnt_arr[arr[row][col] + 1]++;
	else
		rep(i, 3)
			rep(j, 3)
				divide(row + i * nextSize, col + j * nextSize, nextSize);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i, n) 
		rep(j, n)
			cin >> arr[i][j];
	
	divide(0, 0, n);
	rep(i, 3)
		cout << cnt_arr[i] << '\n';
}