#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[13];
int val[13];
int k;
void dfs(int idx, int cnt) {
	// ���� ����
	if (cnt == 6) {
		rep(i,6)
			cout << val[i] << ' ';
		cout << '\n';
		return;
	}
	
	// ��Ʈ��ŷ
	// n�� �� 6�� �̾Ƽ� ����
	for (int i = idx; i < k; i++) {
		// ���� ���� �迭�� ����
		// cnt�� �迭�� �ε����� ���
		val[cnt] = arr[i];
		dfs(i+1, cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	while (k != 0) {
		rep(i, k)
			cin >> arr[i];

		dfs(0, 0);
		cout << '\n';
		cin >> k;
	}
}