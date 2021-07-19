#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, ans, arr[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n)
		cin >> arr[i];
	ans = arr[0];
	for (int i = 1; i < n;i++) {
		arr[i] = max(arr[i], arr[i - 1] + arr[i]);
		ans = max(ans, arr[i]);
	}
	cout << ans;
}