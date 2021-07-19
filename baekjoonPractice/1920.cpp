#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long x;
		cin >> x;
		cout << binary_search(arr, arr + n, x) << '\n';
	}
}
