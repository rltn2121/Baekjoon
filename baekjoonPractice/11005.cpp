#include <iostream>
#include <stack>
using namespace std;
int main() {
	stack<int> s;
	long long n, b;
	cin >> n >> b;

	while (n != 0) {
		s.push(n % b);
		n /= b;
	}

	while (!s.empty()) {
		int a = s.top();
		if (a >= 10)
			cout << (char)(a + 55);
		else
			cout << a;
		s.pop();
	}
}