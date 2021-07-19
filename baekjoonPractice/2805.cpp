#include <iostream>
#define rep(i,n) for(int i = 0; i<n; i++)
using namespace std;
int arr[1000000];
int n, m;
int maxLen;
int func() {
	long long start = 0;
	long long end = 2000000000;
	long long mid = start + (end - start) / 2;
	while (start <= end) {
		mid = start + (end - start) / 2;
		long long len = 0;
		rep(i, n) {
			if (arr[i] > mid)
				len += arr[i] - mid;
		}

		if (len < m)
			end = mid - 1;
		else {
			maxLen = mid;
			start = mid + 1;
		}	
	}
	return maxLen;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i, n)
		cin >> arr[i];
	cout << func();
	
}