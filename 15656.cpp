#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int res[10];
int arr[10];
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		res[k] = arr[i];
		func(k + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	func(0);

}