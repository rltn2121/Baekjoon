#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int a, b, c;
bool isugeon[101];
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;

	// 2�� ��� ã��
	int temp = 1;
	while (temp <= 100) {
		isugeon[temp] = 1;
		temp <<= 1;
	}
	// �Ǻ���
	if (b * b - 4 * a * c <= 0) {
		cout << "�Ѵ�Ʋ�ȱ�";
		return 0;
	}

	// ���� �ٸ� �� ���ε� ���� ���� �ƴϸ�
	if (b % a != 0 || c % a != 0) {
		cout << "�Ѵ�Ʋ�ȱ�";
		return 0;
	}

	// a�� 1�� ����
	b /= a;
	c /= a;
	a = 1;

	// 1. c�� ��� ���ϱ�
	for (int i = 1; i <= abs(c); i++) {
		if (c % i == 0) {
			v.push_back(i);
			v.push_back(-i);
		}
	}

	for (int i : v) {
		int x = i;
		int y = c / x;
		if (x + y == -b) {
			if (x>=2&&y>=2&&isugeon[x] && isugeon[y]) {
				cout << "�̼���";
				return 0;
			}
			else {
				cout << "������";
				return 0;
			}
		}
	}
	cout << "�Ѵ�Ʋ�ȱ�";
}