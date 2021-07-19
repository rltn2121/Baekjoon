#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[10];
int res[10];
bool visited[10];
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return;
	}

	int before = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && before != arr[i]) {
			visited[i] = 1;
			before = arr[i];
			res[k] = arr[i];
			func(k + 1);
			visited[i] = 0;
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