#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int f, m, k;
	int t = 0, n = 0;
	cin >> f >> m >> k;
	if (f >= m * 2) {
		t = m;
		n = f - m * 2;
	}
	else if (f < m * 2) {
		t = f / 2;
		n = m - t + f % 2;
	}
	while (k > n) {
		n += 3;
		t--;
	}
	cout << t << '\n';
}