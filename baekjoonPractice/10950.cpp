#include <iostream>
using namespace std;
int main() {

	int a, b;
	while (cin >> a >> b) {
		if (a == EOF || b == EOF)
			break;
		cout << a + b << '\n';
	}
}