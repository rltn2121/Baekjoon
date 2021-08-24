#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n, h, down[100001], up[100001], min_cnt = 1e9, seg_cnt;
int find(int *arr, int x) {
	int s = 0;
	int e = n/2;
	int ans = n/2;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (x <= arr[mid]) {
			e = mid - 1;
			ans = mid;
		}
		else
			s = mid + 1;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> h;
	rep(i, n / 2) 
		cin >> down[i] >> up[i];
	
	sort(down, down + n / 2);
	sort(up, up + n / 2);
	for (int i = 1; i <= h; i++) {
		int down_cnt = n / 2 - find(down, i);
		int up_cnt = n / 2 - find(up, h + 1 - i);
		int cnt = down_cnt + up_cnt;
		if (cnt < min_cnt) {
			min_cnt = cnt;
			seg_cnt = 1;
		}
		else if (cnt == min_cnt)
			seg_cnt++;
	}
	cout << min_cnt << ' ' << seg_cnt;
}