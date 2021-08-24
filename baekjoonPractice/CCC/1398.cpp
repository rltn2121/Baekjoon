#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int t, arr[101];
ll n, ans;

void init() {
	for (int i = 1; i <= 100; i++) {
		arr[i] = i;

		if (i >= 25) 
			arr[i] = min(arr[i], arr[i - 25] + 1);
		
		if (i >= 10) 
			arr[i] = min(arr[i], arr[i - 10] + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		while (n > 0) {
			int temp = n % 100;
			ans += arr[temp];
			n /= 100;
		}
		cout << ans << '\n';
	}
}
