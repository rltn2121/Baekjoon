#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
int n, ans;
int arr[9];
using namespace std;
int calc() {
	int ret = 0;
	for (int i = 0;i < n - 1;i++)
		ret += abs(arr[i] - arr[i + 1]);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n)
		cin >> arr[i];
	sort(arr, arr + n);
	ans = calc();
	while (next_permutation(arr, arr + n)) 
		ans = max(ans, calc());
	
	cout << ans;
}