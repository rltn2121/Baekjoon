#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int x4, y4;

	x4 = ((x1 == x2 ? x3 : (x2 == x3 ? x1 : x2)));
	y4 = ((y1 == y2 ? y3 : (y2 == y3 ? y1 : y2)));

	cout << x4 << ' ' << y4;
}