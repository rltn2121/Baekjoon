#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	int m, n;
	int set = 0;
	cin >> m;
	while (m--) {
		cin >> str;
		if (str == "add") {
			cin >> n;
			set |= (1 << n);
		}
		else if (str == "remove") {
			cin >> n;
			set &= ~(1 << n);
		}

		else if (str == "check") {
			cin >> n;
			if (set & (1 << n))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "toggle") {
			cin >> n;
			set ^= (1 << n);
		}
		else if (str == "all")
			set |= (1 << 21)-1;

		else if (str == "empty")
			set &= 0;
		
	}
}