#include <iostream>
using namespace std;
bool arr[10001];
void d_n() {
	for (int i = 0; i < 10000; i++) {
		int n = i;
		int ret = n;
		int temp = 0;
		while (n >= 10) {
			temp = n % 10;
			ret += temp;
			n /= 10;
		}
		ret += n;
		if (ret >= 10000)
			ret = 0;

		arr[ret] = true;
	}

	for (int i = 0; i < 10000; i++) {
		if (!arr[i])
			cout << i << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	d_n();
}