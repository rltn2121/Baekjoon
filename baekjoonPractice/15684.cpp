#include <iostream>
#include <algorithm>
using namespace std;
int n, m, h;
int arr[31][11];
int min_cnt = 987654321;
bool chk() {
	// ������ �����ٿ� �������� �� ��߹�ȣ�� ������ȣ ������ Ȯ��
	for (int i = 1; i <= n; i++) {		// ��� ������ �˻�
		int current_col = i;			// ���� ������ ��ġ ����, ������ ������ ����
		for (int j = 1; j <= h; j++) {	// ��� ������ �˻�
			if (arr[j][current_col]==1)	// ���� ��ġ�� ��ٸ��� ������ �װ� Ÿ�� ���������� �̵�
				current_col++;
			else if (arr[j][current_col - 1]==1)	// ���� ��ġ�� ���ʿ� ��ٸ� ������ �װ� Ÿ�� �������� �̵�
				current_col--;
		}

		// ��߹�ȣ ������ȣ �ٸ���
		if (current_col != i)
			return false;
	}
	return true;
}
void dfs(int row, int col, int cnt) {
	// cnt�� 3���� ũ�ų� ���� �ּڰ����� ũ�ų� ������ return (�� �̻� �� �ʿ� ����)
	if (cnt > 3 || cnt >= min_cnt) return;
	if (chk()) {
		min_cnt = min(cnt, min_cnt);
		return;
	}
	
	for(int i = row; i<=h; i++) {	// ��� ������ �˻�
		col = 1;					// ���� ������ �˻��� �� ù ��° �����ٺ��� �˻�
		for(int j=col; j<n; j++) {	// ��� ������ �˻� (������ �������� ������ �˻� ����)
			if (arr[i][j]==0) {		// ���� ��ġ�� ��ٸ� ������
				if (arr[i][j - 1] == 0 && arr[i][j + 1] == 0) {   // ���� ��ġ �� ���� �������� ����� ��
					arr[i][j] = 1;
					dfs(i, j, cnt + 1);
					arr[i][j] = 0;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> h;
	for (int i = 1;i <= m;i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	dfs(1, 1, 0);

	cout << (min_cnt == 987654321 ? -1 : min_cnt);
}