#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int list[10];
int arr[10];
void func(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[cnt] = list[i];
		func(cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> list[i];
	sort(list, list + n);
	func(0);

}