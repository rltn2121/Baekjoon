#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		int temp = i;
		int constructor = temp;
		while (temp >= 10) {
			constructor += temp % 10;
			temp /= 10;
		}
		constructor += temp;
		if (constructor == n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}