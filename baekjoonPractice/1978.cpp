#include <iostream>
using namespace std;
int n, x, cnt = 0;
bool not_prime[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// 에라토스테네스의 체
	not_prime[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (not_prime[i]) continue;
		for (int j = 2; i * j <= 1000; j++)
			not_prime[i * j] = 1;
	}

	cin >> n;
	while (n--) {
		cin >> x;
		if (!not_prime[x])
			cnt++;
	}
	cout << cnt;
}