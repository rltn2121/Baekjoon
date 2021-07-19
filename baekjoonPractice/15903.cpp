#include <iostream>
#include <algorithm>
using namespace std;
long long arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < m; i++) {
		long long temp = 0;
		temp = arr[0] + arr[1];
		arr[0] = temp;
		arr[1] = temp;
		sort(arr, arr + n);
	}
		
	long long ans = 0;
	for (int i = 0;i < n;i++)
		ans += arr[i];
	cout << ans;
	
}