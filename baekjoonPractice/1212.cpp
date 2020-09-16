#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	stack<int> s;
	cin >> str;
	if (str[0] == '0')
		cout << 0 << endl;
	for (int i = 0; i < str.length(); i++)
	{
		int n = (int)str[i] - 48;
		while (n != 0) {
			s.push(n % 2);
			n /= 2;
		}
		if (s.size() < 3 && i != 0) {
			while (s.size() < 3)
				s.push(0);
		}
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
	}
}