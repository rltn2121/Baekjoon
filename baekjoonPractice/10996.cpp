#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j <= n; j++) {
			if (j % 2 == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
		for (int j = 1; j <= n; j++) {
			if (j % 2 == 0)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}