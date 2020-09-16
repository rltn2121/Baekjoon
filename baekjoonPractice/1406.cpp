#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> lstack;
stack<char> rstack;

void insertstring() {
	string str;
	cin >> str;
	for (char c : str)
		lstack.push(c);
}
void movecursorleft() {
	if (lstack.empty())
		return;
	rstack.push(lstack.top());
	lstack.pop();
}
void movecursorright() {
	if (rstack.empty())
		return;
	lstack.push(rstack.top());
	rstack.pop();
}
void deletecursorleft() {
	if (lstack.empty())
		return;
	lstack.pop();
}
void insertcursorleft() {
	char d;
	cin >> d;
	lstack.push(d);
}
void printstring() {
	stack<char> temp;
	while (!lstack.empty()) {
		temp.push(lstack.top());
		lstack.pop();
	}
	while (!temp.empty()) {
		cout << temp.top();
		temp.pop();
	}
	while (!rstack.empty()) {
		cout << rstack.top();
		rstack.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	insertstring();
	int t;
	cin >> t;
	while (t--) {
		char c;
		cin >> c;
		if (c == 'l')
			movecursorleft();
		else if (c == 'd')
			movecursorright();
		else if (c == 'b')
			deletecursorleft();
		else if (c == 'p')
			insertcursorleft();
	}
	printstring();
}