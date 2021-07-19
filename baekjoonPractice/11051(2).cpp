#include <iostream>
using namespace std;
const int N = 1100;
int dp[N][N];

int func(int i, int j) {
	// 기저 단계
	if (i == j || j == 0) return 1;
	if (i == 0) return 0;
	if (j == 1) return i;

	// 메모이제이션 단계
	// reference: ret 변경하면 dp[i][j] 값까지 변경됨
	// ret 안쓰고 전부다 dp[i][j] 넣으면 실행됨
	int &ret = dp[i][j];
	if (ret != -1) 
		return ret;

	// 점화식
	ret = (func(i - 1, j) + func(i - 1, j - 1)) % 10007;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			dp[i][j] = -1;
	}
	int n, k;
	cin >> n >> k;
	cout << func(n, k);
}