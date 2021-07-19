#include <iostream>
#include <algorithm>
using namespace std;
int arr[9], sum = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0;i < 9;i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);

	for (int i = 0; i < 9; i++) {
		sum -= arr[i];
		for (int j = i + 1; j < 9; j++) {
			sum -= arr[j];
			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << arr[k] << '\n';
				}
				break;
			}
			sum += arr[j];
		}
		sum += arr[i];
	}
}