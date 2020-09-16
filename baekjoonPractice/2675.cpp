#include <iostream>
#include <string>
using namespace std;
int main() {
	int t;
	string str;
	cin >> t;
	while (t--) {
		int rep;
		cin >> rep;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < rep; j++)
				cout << str[i];
		}
		cout << endl;
	}
}