#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	bool found = false;
	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int i = 0, j = 0;
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = 999;
				arr[j] = 999;
				found = true;
				break;
			}
		}
		if (found)
			break;
	}

	sort(arr, arr + 9);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << endl;
	
}