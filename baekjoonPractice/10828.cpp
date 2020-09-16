#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int t;
	scanf_s("%d", &t);
	stack<int> s;
	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (cmd == "pop") {
			if (s.empty())
				printf("%d\n", -1);
			else
			{
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if (cmd == "size")
			printf("%d\n", s.size());
		else if (cmd == "empty") {
			if (s.empty())
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if (cmd == "top") {
			if (s.empty())
				printf("%d\n", -1);
			else
				printf("%d\n",s.top());
		}
	}
}