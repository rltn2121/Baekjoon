#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, ans;
struct board {
	int arr[21][21];
	
	// 90�� ȸ��
	void rotate() {
		int temp[21][21];
		rep(i, n) {
			rep(j, n)
				temp[i][j] = arr[n - j - 1][i];
		}

		rep(i, n) {
			rep(j, n)
				arr[i][j] = temp[i][j];
		}
	}

	// �� ������ �ű��
	void move() {
		int temp[21][21];
		// �� ����(������)�� ó��
		rep(j, n) {
			bool flag = 0;	// ��ĥ �� �ִ°�?
			int row = -1;	// temp[][]�� ���� row
			rep(i, n) {
				if (arr[i][j] == 0) continue;
				if (flag && arr[i][j] == temp[row][j]) {	// ��ĥ �� ���� + arr[i] == temp[row]
					temp[row][j] *= 2;						// ���� row���� ��ġ��
					flag = 0;								// ��ĥ �� ������ ����
				}
				else {
					temp[++row][j] = arr[i][j];				// ���� row���� �� ��ġ�Ƿ�, ���� row�� �̵�
					flag = 1;								// ��ĥ �� �ֵ��� ����
				}
			}

			for (int k = row + 1; k < n; k++)				// �� ĭ ä���
				temp[k][j] = 0;
			
		}

		rep(i, n) {
			rep(j, n)
				arr[i][j] = temp[i][j];
		}
	}

	// �ִ�
	int getMax() {
		int ret = 0;
		rep(i, n) {
			rep(j, n)
				ret = max(ret, arr[i][j]);
		}
		return ret;
	}
};

void dfs(board b, int cnt) {
	if (cnt == 5) {
		ans = max(ans, b.getMax());
		return;
	}

	rep(i, 4) {
		// ������ �̵���Ű�� �ȵ�
		board next = b;
		next.move();
		dfs(next, cnt + 1);
		// ���� ȸ����Ű��
		b.rotate();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	board b;
	cin >> n;
	rep(i, n) {
		rep(j, n)
			cin >> b.arr[i][j];
	}
	dfs(b, 0);
	cout << ans;
}