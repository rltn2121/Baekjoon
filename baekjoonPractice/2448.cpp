#include <iostream>
using namespace std;
char arr[3072][6144];

void func(int x, int y, int n) {
	if (n == 3) {
		arr[x][y] = '*';
		arr[x + 1][y - 1] = '*';
		arr[x + 1][y + 1] = '*';
		arr[x + 2][y - 2] = '*';
		arr[x + 2][y - 1] = '*';
		arr[x + 2][y] = '*';
		arr[x + 2][y + 1] = '*';
		arr[x + 2][y + 2] = '*';
		return;
	}
	
	func(x, y, n / 2);
	func(x + n / 2, y - n / 2, n / 2);
	func(x + n / 2, y + n / 2, n / 2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++)
			arr[i][j] = ' ';
	}

	func(0, n-1, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++)
			cout << arr[i][j];
		cout << '\n';
	}
}