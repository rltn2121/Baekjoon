#include <iostream>
using namespace std;
int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int a, b;
		cin >> a >> b;
		cout << "Case #" << i+1 << ": " << a + b << '\n';
	}
}