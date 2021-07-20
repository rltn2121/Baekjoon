#include <iostream>
using namespace std;
long long t, n, i, arr[101];
int main() {
	cin >> t;
	arr[1] = arr[2] = 1;
	for (i = 3;i < 101; i++)
		arr[i] = arr[i - 2] + arr[i - 3];
	while (t--) {
		cin >> n;
		cout << arr[n] << '\n';
	}
}