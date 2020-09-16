#include <iostream>
using namespace std;
int arr[10001];

void initEratos() {
	arr[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		for (int j = i * 2; j <= 10000; j+=i) {
			if (arr[j] == 1)
				continue;
			arr[j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	initEratos();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int a=0, b = 0;
		int mindiff = 99999;
		for (int i = 2; i <= n; i++) {
			if (arr[i] == 0 && arr[n - i] == 0)	{
				int larger = (i > n - i ? i : n - i);
				int smaller = (i < n - i ? i : n - i);
				if (larger - smaller < mindiff) {
					mindiff = larger - smaller;
					a = smaller;
					b = larger;
				}
			}
		}
		cout << a << ' ' << b << '\n';
	}
}