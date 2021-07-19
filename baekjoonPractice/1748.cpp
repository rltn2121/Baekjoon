#include <iostream>
using namespace std;
int n, i, ans;
int pow(int x, int n) {
	if (n == 0)
		return 1;
	return x * pow(x, n - 1);
}
int main() {
	cin >> n;
	i = 1;
	while (n >= pow(10, i)) {
		ans += 9 * pow(10, i - 1) * i;
		i++;
	}
	ans += (n - pow(10, i - 1) + 1) * i;
	cout << ans;
}