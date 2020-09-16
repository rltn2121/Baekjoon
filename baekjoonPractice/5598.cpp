#include <iostream>
#include <string>
using namespace std;
int main() {
	
	string str;
	cin >> str;
	for (char c : str) {
		if (c <= 'C')
			cout << char(c + 23);
		else
			cout << char(c - 3);
	}
}