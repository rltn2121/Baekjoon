#include <iostream>
#include <algorithm>
using namespace std;
// 유클리드 호제법
int gcd(int a, int b) {
	int x = max(a, b);
	int y = min(a, b);
	int r;
	// 1.
	/*while (y > 0) {
		r = x % y;
		x = y;
		y = r;
	}*/
	// 2.
	do {
		r = x % y;
		x = y;
		y = r;
	} while (r > 0);
		return x;
}
int lcm(int a, int b) {
	int common = gcd(a, b);
	return (a / common) * common * (b / common);
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << '\n'
		<< lcm(a, b);
}