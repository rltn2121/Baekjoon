#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int arr[101][101] = { 0, };
	int cnt = 0;
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;

		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				if (arr[i][j] != 1) {
					arr[i][j] = 1;
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
}