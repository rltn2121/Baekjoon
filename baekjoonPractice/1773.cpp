#include <iostream>

int arr[2000001];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(null);

	int n, c;
	int cnt = 0;
	cin >> n >> c;
	while (n--) {
		int a;
		cin >> a;

		for (int i = a; i <= c; i += a) {
			if (arr[i] != 1) {
				arr[i] = 1;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}