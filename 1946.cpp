#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int, int>
using namespace std;
int t, n, ans;
pii arr[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		rep(i, n)
			cin >> arr[i].first >> arr[i].second;
		sort(arr, arr + n);
		ans++;
		int rank = arr[0].second;
		for(int i = 1; i<n; i++) {
			if (arr[i].second < rank) {
				rank = arr[i].second;
				ans++;
			}
		}
		
		cout << ans << '\n';
	}
}