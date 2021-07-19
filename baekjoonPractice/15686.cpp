#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m, arr[51][51];
int cnt = 0, ans = 987654321;
/*
	������ ġŲ �Ÿ� = ��� ���� ġŲ �Ÿ��� ��
	ġŲ �Ÿ� = ���� ������ ���� ����� ġŲ������ �Ÿ�
	m�� ����� ������ �� ���
*/
int chk() {
	int ret = 0;
	rep(i, n) {
		rep(j, n) {
			if (arr[i][j] == 1) {										// ���� ��ġ�� �������̸�
				int tmp = 987654321;
				rep(a, n) {
					rep(b, n) {
						if (arr[a][b] == 2)								// ��� ġŲ������ �Ÿ� ���
							tmp = min(tmp, abs(i - a) + abs(j - b));	// �ּڰ� ����
						
					}
				}
				ret += tmp;									// ������ ġŲ �Ÿ� += ���� ���� ġŲ �Ÿ�
			}
		}
	}
	return ret;
}
void dfs(int x, int y, int now) {
	if (now == m) {					// m���� �������� �Ÿ� üũ
		ans = min(ans, chk());
		return;
	}

	for (int i = x; i <= n; i++) {
		y = 1;
		for (int j = y; j <= n; j++) {
			if (arr[i][j] == 2) {	// ġŲ�� ã���� 0���� ����
				arr[i][j] = 0;		// ���
				dfs(i, j, now - 1);	// ���� 1�� ���̰� ��� Ž��
				arr[i][j] = 2;		// ���� Ž���� ���� ����
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				cnt++;
		}
	}
	dfs(1, 1, cnt);
	cout << ans;
}