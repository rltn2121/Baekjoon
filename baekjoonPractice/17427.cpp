#include <iostream>
using namespace std;
/*
	����� �ƴ� ��� �������� ����
	n = 1,000,000
	2: 2 4 6 ... 999998 1000000		-> 2: 50���� ���Ե�
	3: 3 6 9 ... 999996 999999		-> 3: 33���� ���Ե�
	4: 4 8 12 ... 999996 1000000	-> 4: 25���� ���Ե�
*/
int main() {
	long long n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		ans += (n / i)*i;
	
	cout << ans;
}