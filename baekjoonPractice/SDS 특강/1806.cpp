#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, s, arr[100001], ans = 987654321;
int l, r, sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	rep(i, n)
		cin >> arr[i];

	while (r <= n) {
		if (sum >= s) {
			ans = min(ans, r - l);
			sum -= arr[l];
			l++;
		}
		else if (sum < s) {
			sum += arr[r];
			r++;
		}
	}
	cout << (ans == 987654321 ? 0 : ans);
}