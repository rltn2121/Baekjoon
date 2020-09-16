#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long a, b, c;

	cin >> a >> b >> c;
	if (b >= c)
		cout << -1 << '\n';

	else
		cout << a / (c - b) + 1 << '\n';
	/*else if (a == 0)
		cout << 1 << '\n';

	else {
		int n = ceil(a / (double)(c - b));
		if (a + b * n == c * n)
			n++;
		cout << n << '\n';
	}*/
}