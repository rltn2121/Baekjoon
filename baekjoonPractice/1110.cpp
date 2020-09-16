#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	int a_start = n / 10;
	int b_start = n % 10;
	int a = b_start;
	int b = (a_start + b_start)%10;
	int count = 1;
	while (count ==  1|| a != a_start || b != b_start) {
		int temp = b;
		b = (a + b) % 10;
		a = temp;
		count++;
	}
	cout << count << endl;
}