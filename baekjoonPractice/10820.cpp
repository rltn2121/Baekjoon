#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	char space = ' ';
	int arr[4] = { 0, };
	while (getline(cin, str)) {
		arr[0] = arr[1] = arr[2] = arr[3] = 0;
		for (char c : str) {
			if (islower(c))
				arr[0]++;
			else if (isupper(c))
				arr[1]++;
			else if (isdigit(c))
				arr[2]++;
			else if (c == space)
				arr[3]++;

		}
	
		for (int i = 0; i < 4; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
	
}
