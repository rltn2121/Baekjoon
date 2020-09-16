#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, h, w, n;
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		int y = n % h;
		if (y == 0)
			y = h;
		int x = (n % h == 0? n / h : n / h + 1);
		printf("%d%.2d\n", y, x);
		
	}
}