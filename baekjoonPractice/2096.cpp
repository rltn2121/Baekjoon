#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n;
int arr[100000][3], prev_max[3], now_max[3], prev_min[3], now_min[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		rep(j, 3)
			cin >> arr[i][j];
	}

	rep(i, 3) {
		prev_max[i] = arr[0][i];
		now_max[i] = arr[0][i];
		prev_min[i] = arr[0][i];
		now_min[i] = arr[0][i];
	}


	for(int i = 1; i<n; i++) {
		now_max[0] = arr[i][0] + max(prev_max[0], prev_max[1]);
		now_max[1] = arr[i][1] + max(prev_max[0], max(prev_max[1], prev_max[2]));
		now_max[2] = arr[i][2] + max(prev_max[1], prev_max[2]);

		now_min[0] = arr[i][0] + min(prev_min[0], prev_min[1]);
		now_min[1] = arr[i][1] + min(prev_min[0], min(prev_min[1], prev_min[2]));
		now_min[2] = arr[i][2] + min(prev_min[1], prev_min[2]);

		rep(j, 3) {
			prev_max[j] = now_max[j];
			prev_min[j] = now_min[j];
		}
	}

	cout << max(now_max[0], max(now_max[1], now_max[2])) << ' ';
	cout << min(now_min[0], min(now_min[1], now_min[2]));
}