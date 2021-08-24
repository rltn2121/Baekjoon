#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int t, n, arr[1001];
int dp[1001][1001];	// i ~ j 구간의 최선전략에서 근우의 점수

int func(int l, int r) {
	if (l > r) return 0;
	if (dp[l][r]) return dp[l][r];

	// 카드가 2장 남음
	if (r - l <= 1)
		return dp[l][r] = max(arr[l], arr[r]);

	// 1. 근우가 왼쪽을 뽑는 경우
	//  - 명우가 왼쪽 뽑음 -> func(l+2, r)
	//  - 명우가 오른쪽 뽑음 -> func(l+1, r-1)
	int left_case = arr[l] + min(func(l+2, r), func(l+1, r-1));

	// 2. 근우가 오른쪽을 뽑는 경우
	//  - 명우가 왼쪽 뽑음 -> func(l+1, r-1)
	//  - 명우가 오른쪽 뽑음 -> func(l, r-2)
	int right_case = arr[r] + min(func(l + 1, r - 1), func(l, r - 2));

	// 1번과 2번 중에서 더 큰 값
	dp[l][r] = max(left_case, right_case);
	return dp[l][r];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		rep(i, n)
			cin >> arr[i];
		cout << func(1, n) << '\n';
	}
}