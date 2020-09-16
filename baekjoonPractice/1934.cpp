#include <iostream>
using namespace std;
int getGCD(int a, int b) {
	int min = (a < b ? a : b);
	int gcd = 1;
	for (int i = 2; i <= min; i++) {
		if (a % i == 0 && b % i == 0)
			gcd = i;
	}
	return gcd;
}
int getLCM(int a, int b) {
	int gcd = getGCD(a, b);
	int x = a / gcd;
	int y = b / gcd;
	return x * y * gcd;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << getLCM(a, b) << '\n';
	}
}