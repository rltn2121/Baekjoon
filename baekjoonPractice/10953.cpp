#include <iostream>
using namespace std;
int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int a, b;
		scanf_s("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
}