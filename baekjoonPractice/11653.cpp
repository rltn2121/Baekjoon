#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	int temp = n;
	for (int i = 2; i <= temp; i++) {
		while (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}
}