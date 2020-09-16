#include <iostream>
using namespace std;
int arr[10001];
int sum(int a, int b) {
	int ret = 0;
	for (int i = a; i < b; i++)
		ret += arr[i];
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int start = 0, end = 0;
	int cnt = 0;
	while (start <= end) {
		if (sum(start, end) == m)
			cnt++;
		if (sum(start, end) > m || end == n)
			start++;
		else
			end++;
	}
	cout << cnt << '\n';
}