#include <iostream>
using namespace std;

void han(int n) {
	if (n < 100)
		cout << n << '\n';

	else {
		int total = 0;
		for (int i = 100; i <= n; i++) {
			int temp = i;
			int a = temp % 10;
			temp /= 10;
			int b = temp % 10;
			temp /= 10;
			int c = temp;

			if (a - b == b - c)
				total++;
		}
		cout << total+99 << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a;
	cin >> a;
	han(a);
}