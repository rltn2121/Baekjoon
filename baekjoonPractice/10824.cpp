#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b, c, d;
	cin >> a >> b >> c >> d;
	a.append(b);
	c.append(d);

	long long x = 0;
	long long x_pos = 1;
	for (int i = a.length() - 1; i >= 0; i--) {
		x += ((long long)a[i]-48) * x_pos;
		x_pos *= 10;
	}

	long long y = 0;
	long long y_pos = 1;
	for (int i = c.length() - 1; i >= 0; i--) {
		y += ((long long)c[i]-48) * y_pos;
		y_pos *= 10;
	}
	cout << x + y << endl;
}