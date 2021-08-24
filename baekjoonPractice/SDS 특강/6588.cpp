#include <iostream>
using namespace std;
int n, k, cnt;
bool notPrime[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	notPrime[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (notPrime[i]) continue;
		for (int j = i+i; j <= 1000000; j += i) {
			if (notPrime[j]) continue;
			notPrime[j] = 1;
		}
	}

	cin >> n;
	while (n != 0) {
		for (int i = 3; i <= 1000000; i += 2) {
			if (!notPrime[i] && !notPrime[n-i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
		cin >> n;
	}
}