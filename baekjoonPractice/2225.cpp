#include <iostream>
using namespace std;
int n, k, arr[201][201];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		arr[i][1] = i;
	for (int i = 1; i <= n; i++)
		arr[1][i] = 1;

	for (int i = 2; i <= k; i++) {
		for (int j = 2; j <= n; j++)
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000000;
	}
	cout << arr[k][n];
}