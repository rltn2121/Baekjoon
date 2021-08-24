#include <iostream>
#include <algorithm>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
ll n, m, arr[1000000], sum, ans;
ll max_height = -1, min_height = 1000000001;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i, n) {
		cin >> arr[i];
		max_height = max(max_height, arr[i]);
	}
		
	min_height = 0;
	ll mid = 0;
	while (min_height <= max_height) {
		mid = (max_height + min_height) / 2;

		sum = 0;
		rep(i, n) {
			if (arr[i] >= mid)
				sum += (arr[i] - mid);
		}

		if (sum == m) {
			cout << mid;
			return 0;
		}
		// ≥Ù¿Ã∏¶ ≥Ùø©µµ µ 
		else if (sum > m) {
			min_height = mid + 1;
			ans = max(ans, mid);
		}

		// ≥Ù¿Ã∏¶ ≥∑√Áæﬂ«‘
		else if (sum < m) {
			max_height = mid - 1;
		}
	}
	cout << ans;
		

}