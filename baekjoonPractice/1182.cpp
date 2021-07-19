#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[21];
int n, s, sum, ans = 0;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	rep(i, n)
		cin >> arr[i];
	
	int mask = 1;
	while (mask < (1 << n)) {
		sum = 0;
		for (int i = 0;i < n;i++)
			sum += arr[i] * ((mask >> i) & 1);
		if (sum == s)
			ans++;
		mask++;
	}
	cout << ans;
}