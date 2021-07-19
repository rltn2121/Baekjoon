#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, l, cnt = 0, arr[200][100];
bool flag;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l;
	rep(i, n) {
		rep(j, n)
			cin >> arr[i][j];
	}

	// ���θ� ���η� ä���ֱ�
	rep(i, n) {
		rep(j, n)
			arr[n + i][j] = arr[j][i];
	}
	rep(i, 2*n) {
		flag = true;
		int a = 0;										// Ž���� ���� ��������
		int b = 1;
		while (b < n) {
			if (abs(arr[i][a] - arr[i][b]) > 1) {		// 1. ���̰� 1 �̻� -> ��� ����
				flag = false;
				break;
			}

			if (arr[i][a] == arr[i][b]) {				// 2. ���̰� ���� -> ������ �̵�
				a++;
				b++;
			}

			else if (arr[i][a] > arr[i][b]) {			// ���� �� -> ���� �� (3 -> 2) : b�� l��ŭ ���������� �̵�
				int j;
				for (j = b; j < b + l; j++) {			// 1. b�� ���������� l��ŭ �̵���ų �� �ִ��� Ȯ�� 
					if (j == n)							//   1) �̵� �߿� �迭 ���� ���� -> �Ұ�
						break;							
					if (arr[i][j] != arr[i][a] - 1)		//   2) �̵� �߿� ���̰� �޶���  -> �Ұ�
						break;
				}
				if (j != b + l) {						// 2. b�� l��ŭ �̵��ߴ��� Ȯ�� (���� ���� ���� Ȯ���ߴ� ��)
					flag = false;						//   1) �̵� ����: ���� �� Ž�� ����. ���� �� Ž��
					break;
				}

				a = b + l - 1;							//   2) �̵���: �����͸� ���� �� �������� �̵�

				for (j = a + 1; j <= a + l; j++) {		// 3. (���� �� ���� ~ ���� �� ���� + l) ���̿� �ö󰡴� ������ �ִ��� �˻�
					if (j == n)								// �迭 ���� ���� : break
						break;								
					if (arr[i][j] > arr[i][a]) {			// ���� �ö� : �Ұ�
						flag = false;						
						break;
					}
				}
				if (!flag)									// �ܼ��� �ش� ������ �ö󰡴� ������ �ִ����� �˻��ϴ� ���̹Ƿ�
					break;									// �ö󰡴� ������ ������ ���� �迭 ���� �����ؼ� �����ߴٸ� (j = a + l = n)
															// break ���ص� ��
				b = a + 1;
			}

			else if (arr[i][a] < arr[i][b]) {			// ���� �� -> ���� �� (2 -> 3) : a�� l��ŭ �������� �̵�
				int j;
				for (j = a; j > a - l; j--) {			// 1. a�� �������� l��ŭ �̵���ų �� �ִ��� Ȯ��
					if (j < 0)							//   1) �̵� �߿� �迭 ���� ���� -> �Ұ�
						break;
					if (arr[i][j] != arr[i][b] - 1)		//   2) �̵� �߿� ���̰� �޶���  -> �Ұ�
						break;
				}
				if (j != a - l) {						// 2. a�� l��ŭ �̵��ߴ��� Ȯ�� (���� ���� ���� Ȯ���ߴ� ��)
					flag = false;						//   1) �̵� ����: ���� �� Ž�� ����. ���� �� Ž��
					break;								
				}
				a = b;									//   2) �̵���: ������ �̵� �� ��� Ž��
				b = a + 1;
			}
		}
		if (flag) cnt++;
	}
	cout << cnt;
}
