#include <iostream>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b >> c;
	if (a == b == c) {
		cout << a;
		return 0;
	}
	int i = 1;
	while (1) {
		if ((i % 15 + 1) == a && (i % 28 + 1) == b && (i % 19 + 1) == c) {
			cout << i+1;
			break;
		}
		i++;
	}
}