#include <iostream>
using namespace std;
int t, m, n, x, y;
int gcd(int x, int y) {
	int r;
	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
int lcm(int x, int y) {
	int g = gcd(x, y);
	return (x / g) * g * (y / g);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> m >> n >> x >> y;
		int last = lcm(m,n);
		while (1) {
			if (x > last) {
				cout << -1 << '\n';
				break;
			}
			
			if ((x - 1) % n == y - 1) {
				cout << x << '\n';
				break;
			}
			x += m;
		}
	}
}