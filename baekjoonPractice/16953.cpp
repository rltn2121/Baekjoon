#include <iostream>
using namespace std;
int a, b, cnt, last;
int main() {
	cin >> a >> b;
	
	// ������ �ȵ� (b = -1 -> while �ȵ�)
	if (a == b) 
		b = -1;
	
	// b == a �̰ų� b < a �̸� ���
	while (b>a) {
		last = b % 10;
		// ������ ���ڰ� 3, 5, 7, 9 �� �� ����
		if (last > 1 && last % 2 == 1) break;

		// ������ ���ڰ� 1�̸� 1 ����
		// ������ ���ڰ� 2�� ����̸� 2�� ����
		last == 1 ? b /= 10 : b /= 2;
		cnt++;
	}
	cout << (b == a ? cnt + 1 : -1);
}