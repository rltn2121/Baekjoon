#include <iostream>
using namespace std;
int n, ans, arr[101];
int main() {
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	for (int i = n - 1; i > 0; i--) {
		if (arr[i - 1] >= arr[i]) {
			ans+=arr[i - 1] - (arr[i] - 1);
			arr[i - 1] = arr[i] - 1;
		}
	}
	cout << ans;
}