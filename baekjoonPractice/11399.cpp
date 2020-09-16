#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int arr[1001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int sum = arr[0];
	for (int i = 0; i < n-1; i++) {
		arr[i + 1] += arr[i];
		sum += arr[i + 1];
	}
	cout << sum << endl;
}