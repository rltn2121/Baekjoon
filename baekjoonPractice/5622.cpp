#include <iostream>
#include <string>
using namespace std;
int charToNum(char c) {
	if (c <= 'C')
		return 3;
	else if (c <= 'F')
		return 4;
	else if (c <= 'I')
		return 5;
	else if (c <= 'L')
		return 6;
	else if (c <= 'O')
		return 7;
	else if (c <= 'S')
		return 8;
	else if (c <= 'V')
		return 9;
	else if (c <= 'Z')
		return 10;
}
int main() {
	string str;
	cin >> str;
	int sum = 0;
	for (char c : str) {
		sum+=charToNum(c);
	}
	cout << sum;
}