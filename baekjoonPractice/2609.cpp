#include <iostream>
using namespace std;
int getGCD(int a, int b) {
	int min = (a < b ? a : b);
	int gcd = 1;
	for (int i = 2; i <= min; i++) {
		if (a%i == 0 && b%i == 0)
			gcd = i;
	}
	return gcd;
}
int getLCM(int a, int b, int gcd) {
	int x = a / gcd;
	int y = b / gcd;
	return x * y * gcd;
}
int main() {
	int a, b;
	cin >> a >> b;
	int gcd = getGCD(a, b);
	cout <<  gcd<< endl;
	cout << getLCM(a, b, gcd) << endl;
}