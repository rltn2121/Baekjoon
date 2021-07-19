#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pii pair<int, int>
using namespace std;
int n, ans = -1;
pii arr[16];
void dfs(int now, int sum) {
	ans = max(ans, sum);
	for (int i = now; i <= n; i++) {					// ��� ��¥ �� Ž��
		if (i + arr[i].first <= n+1)					// ���� ����� n+1�� �ȿ� ������
			dfs(i + arr[i].first, sum + arr[i].second);	// �� ��¥�� �̵�, �� ����
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n)
		cin >> arr[i].first >> arr[i].second;
	dfs(1, 0);
	cout << ans;
}