#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = arr[0];
	for (int i = 1; i < n; i++) {
		arr[i] = arr[i] + max(0, arr[i - 1]);
		ans = ans > arr[i] ? ans : arr[i];
	}
	cout << ans;
}