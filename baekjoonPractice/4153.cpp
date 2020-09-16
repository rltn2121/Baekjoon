#include <iostream>
using namespace std;
int main() {
	long long a=0, b=0, c=0;
	cin >> a >> b >> c;
	while (!(a==0 && b==0 && c==0)) {
		cout << ((c * c == a * a + b * b)||(b * b == a * a + c * c)||(a * a == c * c + b * b) ? "right\n" : "wrong\n");
		cin >> a >> b >> c;
	}
}