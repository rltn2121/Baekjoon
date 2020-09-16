#include <iostream>
using namespace std;
int main() {
	int arr[3];
	int x, y;
	cin >> x >> y;

	for (int i = 2; i >= 0; i--) {
		arr[i] = y % 10;
		y /= 10;
	}

	cout << x*arr[2] << endl
		<< x*arr[1] << endl
		<< x*arr[0] << endl
		<< x*arr[0] * 100 + x*arr[1] * 10 + x*arr[2] << endl;

}