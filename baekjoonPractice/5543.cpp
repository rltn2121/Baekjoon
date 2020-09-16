#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int b1, b2, b3, d1, d2;

	cin >> b1 >> b2 >> b3 >> d1 >> d2;

	int min_burger = b1;
	int min_drink = d1;

	min_burger = (b2 < min_burger ? b2 : min_burger);
	min_burger = (b3 < min_burger ? b3 : min_burger);

	min_drink = (d2 < min_drink ? d2 : min_drink);

	cout << min_burger + min_drink - 50 << '\n';

}