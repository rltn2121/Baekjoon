#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, arr[10000], sum[10000], ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	rep(i, n) {
		cin >> arr[i];
		if (i > 0)
			sum[i] = sum[i - 1] + arr[i];
		else
			sum[i] = arr[i];

		if (sum[i] == m)
			ans++;
	}


	for(int i = 1; i<n; i++) {
		for(int j = 0; j<i; j++){
			if (sum[i] - sum[j] == m)
				ans++;
		}
	}

	cout << ans;
}