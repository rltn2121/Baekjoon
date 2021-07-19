#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, arr[1000001];
int ans = -1, num;
int gcd[1000001];
int gcd_rev[1000001];;
int getGCD(int a, int b) {
	if (b == 0) return a;
	return getGCD(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	rep(i, n)
		cin >> arr[i];

	gcd[0] = arr[0];
	for (int i = 1; i < n; i++)
		gcd[i] = getGCD(gcd[i - 1], arr[i]);

	gcd_rev[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		gcd_rev[i] = getGCD(gcd_rev[i + 1], arr[i]);

	for (int i = 0; i < n; i++) {
		int temp;
		if (i == 0)
			temp = gcd_rev[1];
		else if (i == n - 1)
			temp = gcd[n - 2];
		else
			temp = getGCD(gcd[i - 1], gcd_rev[i + 1]);
		if (arr[i] % temp == 0) continue;

		if (temp > ans) {
			ans = temp;
			num = arr[i];
		}
	}

	if (ans == -1) {
		cout << ans;
		return 0;
	}
	cout << ans << ' ' << num;
}