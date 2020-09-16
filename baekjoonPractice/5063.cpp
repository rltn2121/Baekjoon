#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a < b - c)
			cout << "advertise" << endl;
		else if (a > b - c)
			cout << "do not advertise" << endl;
		else
			cout << "does not matter" << endl;
	}
}