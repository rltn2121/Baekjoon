#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int space = 0;
	for (int i = 2*n-1; i >=n; i--) {
		for (int j = 0; j < i; j++) {
			if (j < space)
				cout << ' ';
			else
				cout << '*';
		}
		cout << endl;
		space++;
	}
	
	space -= 2;
	
	for (int i = n+1; i <= 2 * n - 1; i++) {
		for (int j = 0; j <i; j++) {
			if (space - j > 0)
				cout << ' ';
			else
				cout << '*';

		}
		space--;
		cout << endl;
	}
}