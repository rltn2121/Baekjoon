#include <iostream>
#include <string>
using namespace std;
int power(int n, int k) {
	if (k == 0)
		return 1;
	if (k == 1)
		return n;
	return n * power(n, k - 1);
}
int main() {
	string str;
	int b;
	cin >> str >> b;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] < 65)
			str[i] = (int)str[i] - 48;
		else
			str[i] = (int)str[i] - 55;
	}
	
	int sum = 0;
	int j = str.length() - 1;
	for (int i = 0; i < str.length(); i++)
		sum += (int)str[j--] * power(b, i);
	cout << sum << endl;
}