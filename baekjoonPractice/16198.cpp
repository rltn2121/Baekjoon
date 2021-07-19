#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, arr[11], ans;
bool visited[11];
// idx �� �� ���� ����
int calc(int idx) {
	int ret = 0;
	for (int i = idx - 1; i >= 0; i--) {	// 0 �ƴ� ���� ���� ������ �������� �̵�
		if (arr[i] != 0) {
			ret += arr[i];
			break;
		}
	}
	for (int i = idx + 1; i < n; i++) {		// 0 �ƴ� ���� ���� ������ ���������� �̵�
		if (arr[i] != 0) {
			ret *= arr[i];
			break;
		}
	}
	return ret;
}
void bfs(int cnt, int sum) {
	if (cnt == n-1) {
		ans = max(ans, sum);
		return;
	}
	// 0 / 1 ~ n-2 / n-1 ����
	for (int i = 1; i <= n-2; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			int temp = arr[i];
			arr[i] = 0;					// ������ ���ڸ� 0���� ����
			bfs(cnt+1, sum+calc(i));	// ��� �Ŀ� ���� �ܰ� ����
			arr[i] = temp;
			visited[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n)
		cin >> arr[i];
	bfs(1, 0);
	cout << ans;
}