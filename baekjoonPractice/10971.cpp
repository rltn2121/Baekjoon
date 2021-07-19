#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, ans, arr[11][11];
int idx_arr[11];	// Ž�� ���� ����

int calc() {
	int ret = 0;
	for (int i = 0;i < n - 1;i++){
		// 0�̸� ����
		if (arr[idx_arr[i]][idx_arr[i + 1]] == 0)
			return 987654321;

		// ���� ���÷� �̵�
		ret += arr[idx_arr[i]][idx_arr[i + 1]];
	}
	// 0�̸� ����
	if (arr[idx_arr[n - 1]][idx_arr[0]] == 0)
		return 987654321;

	// ������ ���� -> ó�� ����
	ret += arr[idx_arr[n - 1]][idx_arr[0]];
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n) {
		idx_arr[i] = i;
		rep(j, n)
			cin >> arr[i][j];
	}
	ans = calc();
	while (next_permutation(idx_arr, idx_arr + n))
		ans = min(ans, calc());
	cout << ans;
}