#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int x_min = (x < w - x ? x : w - x);
	int y_min = (y < h - y ? y : h - y);

	cout << (x_min < y_min ? x_min : y_min);
}