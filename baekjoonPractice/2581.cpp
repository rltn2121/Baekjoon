#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	if (n == 1)
		return false;
	if (n == 2)
		return true;
	int rootsqure = ceil(sqrt(n));

	for (int i = 2; i <= rootsqure; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	int sum = 0;
	int min = 0;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (isPrime(i)) {
			if (min == 0)
				min = i;
			sum += i;
		}
	}
	if (sum != 0)
		cout << sum << '\n' << min << '\n';
	else
		cout << -1 << endl;
}