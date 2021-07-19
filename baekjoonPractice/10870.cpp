#include <iostream>
using namespace std;
int fib(int x) {
	if (x <= 1) return x;
	return fib(x - 1) + fib(x - 2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	cin >> x;
	cout << fib(x);
}