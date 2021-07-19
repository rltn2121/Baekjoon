#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[10];
int res[10];
void func(int k) {
	if (k == m) {
		int min = res[0];
		for (int i = 1; i < m; i++) {
			if (min > res[i])
				return;
			min = res[i];
		}
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return;
	}

	int before = -1;
	for (int i = 0; i < n; i++) {
		if (before != arr[i]) {
			before = arr[i];
			res[k] = arr[i];
			func(k + 1);
		}
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