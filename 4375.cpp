#include <iostream>
using namespace std;
long long n;
int main() {
	while (cin >> n) {	// while(!cin.eof()) 하면 틀림
		int ans = 1;
		long long div = 1;
		while (div % n != 0) {
			div = div * 10 + 1;
			div %= n;	// 여기가 핵심
						// (x mod n) == ( (x mod n) mod n)
			ans++;
		}
		cout << ans << '\n';
	}
}