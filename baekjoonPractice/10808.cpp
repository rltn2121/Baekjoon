#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	int alphaCount[26] = { 0 };
	cin >> str;
	for (int i = 0; str[i]; i++) {
		alphaCount[str[i] - 'a']++;
	}

	for (int i = 0; i<26; i++) {
		cout << alphaCount[i] << ' ';
	}
}