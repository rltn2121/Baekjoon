#include <iostream>
#include <string>
using namespace std;
int main() {
	while (1) {
		int n;
		cin >> n;
		cin.ignore();
		if (n == 0)
			break;
		size_t idx = 0;
		for (size_t i = 0; i < n; i++) {
			string str;
			getline(cin, str);

			while (idx < str.length() && str[idx] != ' ')
				idx++;
		}
		cout << idx+1 << endl;
	}
}