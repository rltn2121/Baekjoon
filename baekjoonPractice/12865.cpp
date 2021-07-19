#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, k;
int dp[101][100001];
struct Node {
	int w, v;
	bool operator<(Node n) {
		return w < n.w;
	}
};
Node arr[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	rep(i, n)
		cin >> arr[i].w >> arr[i].v;
	sort(arr, arr + n);
	rep(i, n) {
		rep(j, k) {
			int capacity = j;
			int weight = arr[i].w;
			if (weight > capacity) dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], arr[i].v + dp[i - 1][capacity - weight]);
			
		}
	}
	cout << dp[n][k];
}