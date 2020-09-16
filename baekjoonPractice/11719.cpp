#include <iostream>
#include <string>
using namespace std;

int main() {

	int count = 0;
	while (count < 100) {
		string str;
		getline(cin, str);
		cout << str << endl;
		count++;
	}
}