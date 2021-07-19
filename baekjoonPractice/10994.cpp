#include <iostream>
using namespace std;
char arr[401][401];
void func(int x, int y, int n) {
	if (n == 1)
		return;
	
	for (int i = x + 1; i < x + 4 * (n - 1); i++){
		arr[x + 1][i] = ' ';
		arr[x + 4 * n - 5][i] = ' ';
		arr[i][y + 1] = ' ';
		arr[i][y + 4 * n - 5] = ' ';
	}

	func(x + 2, y + 2, n - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n * 4 + 1; i++) {
		for (int j = 0; j < n * 4 + 1; j++)
			arr[i][j] = '*';
	}

	func(0, 0, n);

	for (int i = 0; i <= 4*(n-1); i++) {
		for (int j = 0; j <= 4 * (n - 1); j++)
			cout << arr[i][j];
		cout << '\n';
	}
}
