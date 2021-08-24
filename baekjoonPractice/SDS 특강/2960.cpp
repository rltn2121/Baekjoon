#include <iostream>
using namespace std;
int n, k, cnt;
bool notPrime[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	notPrime[1] = 1;
	for (int i = 2; i <= n; i++) {

		for (int j = i; j <= n; j += i) {
			if (notPrime[j]) continue;
			notPrime[j] = 1;
			if (++cnt == k) {
				cout << j;
				return 0;
			}
		}
	}


}