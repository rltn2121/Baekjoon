//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//stack<char> lStack;
//stack<char> rStack;
//
//void insertString() {
//	string str;
//	cin >> str;
//	for (char c : str)
//		lStack.push(c);
//}
//void moveCursorLeft() {
//	if (lStack.empty())
//		return;
//	rStack.push(lStack.top());
//	lStack.pop();
//}
//void moveCursorRight() {
//	if (rStack.empty())
//		return;
//	lStack.push(rStack.top());
//	rStack.pop();
//}
//void deleteCursorLeft() {
//	if (lStack.empty())
//		return;
//	lStack.pop();
//}
//void insertCursorLeft() {
//	char d;
//	cin >> d;
//	lStack.push(d);
//}
//void printString() {
//	stack<char> temp;
//	while (!lStack.empty()) {
//		temp.push(lStack.top());
//		lStack.pop();
//	}
//	while (!temp.empty()) {
//		cout << temp.top();
//		temp.pop();
//	}
//	while (!rStack.empty()) {
//		cout << rStack.top();
//		rStack.pop();
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	
//	insertString();
//	int t;
//	cin >> t;
//	while (t--) {
//		char c;
//		cin >> c;
//		if (c == 'L')
//			moveCursorLeft();
//		else if (c == 'D')
//			moveCursorRight();
//		else if (c == 'B')
//			deleteCursorLeft();
//		else if (c == 'P')
//			insertCursorLeft();
//	}
//	printString();
//}