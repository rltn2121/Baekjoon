#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, sum=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	if (sum <= m) {
		cout << arr[n - 1];
		return 0;
	}

	int left=0, mid, right, ans;
	right = arr[n - 1];
	while (1) {
		if (left > right)
			break;
		mid = (left + right) / 2;
		int temp = m;
		for (int i = 0; i < n; i++) {
			if (arr[i] <= mid)
				temp -= arr[i];
			else
				temp -= mid;
		}

		if (temp == 0) {
			ans = mid;
			break;
		}

		else if (temp > 0) {
			left = mid + 1;
			ans = mid;
		}

		else if (temp < 0)
			right = mid - 1;
	}
	cout << ans;
}