#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (b - 45 < 0)
	{
		a--;
		b += 60;
	}
	if (a < 0)
		a = 23;
	cout << a << ' ' << b - 45 << endl;
}