#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if ((int)c >= 65 && (int)c <= 90){
			c -= 65;
			c += 13;
			c %= 26;
			c += 65;
		}
		else if ((int)c >= 97 && (int)c <= 122) {
			c -= 97;
			c += 13;
			c %= 26;
			c += 97;
		}
		str[i] = (char)c;
	}
	cout << str;

}