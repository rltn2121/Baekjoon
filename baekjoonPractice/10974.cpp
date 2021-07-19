#include <iostream>
#include <algorithm>
using namespace std;
int arr[8];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		arr[i] = i + 1;
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	while (next_permutation(arr, arr + n)) {
		cout << '\n';
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
	}
}