#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++)	{
				if (i == 0 || j == 0 || i == a - 1 || j == a - 1)
					cout << '#';
				else
					cout << 'J';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}