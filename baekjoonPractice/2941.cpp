#include <iostream>
using namespace std;
int main() {
	int count = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '=') {
			if (str[i - 1] == 'z' && str[i - 2] == 'd') {
				count--;
				continue;
			}

			else if (str[i - 1] == 'c' || str[i - 1] == 's' || str[i - 1] == 'z')
				continue;
		}

		else if (str[i] == 'j' && (str[i - 1] == 'l' || str[i - 1] == 'n'))
			continue;

		else if (str[i] == '-' && (str[i - 1] == 'c' || str[i - 1] == 'd'))
			continue;
		

		count++;
	}

	cout << count << endl;
}