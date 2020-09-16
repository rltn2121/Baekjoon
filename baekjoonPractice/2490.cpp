#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int a;
			cin >> a;
			sum += a;
		}
		if (sum == 0)
			cout << 'D' << endl;
		else if (sum == 1)
			cout << 'C' << endl;
		else if (sum == 2)
			cout << 'B' << endl;
		else if (sum == 3)
			cout << 'A' << endl;
		else
			cout << 'E' << endl;
	}
}