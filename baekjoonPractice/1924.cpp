#include <iostream>
using namespace std;
int main() {
	string arr[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int m, d;
	cin >> m >> d;
	
	if (m == 5)
		d += 1;
	else if (m == 8)
		d += 2;
	else if (m == 2 || m == 3 || m == 11)
		d += 3;
	else if (m == 6)
		d += 4;
	else if (m == 9 || m == 12)
		d += 5;
	else if (m == 4 || m == 7)
		d += 6;
	cout << arr[d%7] << endl;
}
