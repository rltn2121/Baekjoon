#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int arr[101][101] = { 0, };
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				if (arr[j][k] != 1)
				{
					arr[j][k] = 1;
						cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
}