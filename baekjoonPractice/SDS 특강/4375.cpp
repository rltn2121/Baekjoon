#include <iostream>
#define ll long long
using namespace std;
ll n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n) {
		int cnt = 2;

		ll x = 11;
		while (x % n != 0) {
			x = x * 10 + 1;
			x %= n;
			cnt++;
		}
		cout << cnt << '\n';
	}
}