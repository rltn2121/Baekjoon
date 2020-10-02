#include <iostream>
using namespace std;
int getGCD(int a, int b) {
	int x = (a > b ? a : b);
	int y = (a < b ? a : b);
	int r = x % y;
	while (r != 0) {
		r = x % y; 
		x = y;
		y = r;
	}
	return x;
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