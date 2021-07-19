#include <iostream>
using namespace std;
int l, p, v, ans, i = 1;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> p >> v;
	while (!(l == 0 && p == 0 && v == 0)) {
		ans = 0;
		while (v - p >= 0) {
			ans += l;
			v -= p;
		}

		if (v >= l)
			ans += l;

		else
			ans += v;
		
		cout << "Case " << i++ << ": " << ans << '\n';
			
		cin >> l >> p >> v;
	}
}