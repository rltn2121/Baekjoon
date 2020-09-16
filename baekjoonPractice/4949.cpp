#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	
	getline(cin, str);

	while (str != ".") {
		bool possible = true;
		stack<char> s;
		for (char c : str) {
			if (c == '(' || c == '[')
				s.push(c);

			else if (c == ')') {
				if (!s.empty() && s.top() == '(')
					s.pop();
				else{
					possible = false;
					break;
				}
			}

			else if (c == ']') {
				if (!s.empty() && s.top() == '[')
					s.pop();
				else {
					possible = false;
					break;
				}
			}
			else
				continue;
		}
		if (!s.empty())
			possible = false;
		if (possible)
			cout << "yes\n";
		else
			cout << "no\n";
		getline(cin, str);
	}


}