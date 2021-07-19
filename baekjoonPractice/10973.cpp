#include <iostream>
#include <algorithm>
using namespace std;
int arr[10000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> arr[i];

	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			prev_permutation(arr, arr + n);
			for (int i = 0;i < n;i++)
				cout << arr[i] << ' ';
			return 0;
		}
	}
	cout << -1;
}