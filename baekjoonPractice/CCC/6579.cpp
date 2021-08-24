#include <iostream>
#include <string>
#include <stack>
#include <queue>
#define pii pair<int, int>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
string str;
stack<string> str_stack;
stack<pii> op_stack;
int idx;
int friends[256][26];
void func() {
	string b = str_stack.top(); str_stack.pop();
	string a = str_stack.top(); str_stack.pop();
	char op = op_stack.top().first; op_stack.pop();
	bool a_arr[26] = { 0, };
	bool b_arr[26] = { 0, };
	for (char c : a)
		a_arr[c - 'A'] = 1;
	for (char c : b)
		b_arr[c - 'A'] = 1;
	if (op == '+') {
		rep(i, 26)
			a_arr[i] |= b_arr[i];
	}
	else if (op == '-') {
		rep(i, 26) {
			if (a_arr[i] && !b_arr[i]) a_arr[i] = 1;
			else a_arr[i] = 0;
		}
	}
	else if (op == '*') {
		rep(i, 26)
			a_arr[i] &= b_arr[i];
	}
	string ret = "";
	rep(i, 26)
		if (a_arr[i]) ret += (i + 'A');

	str_stack.push(ret);
}

void init();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> str) {
		string result = "";
		string temp = "";
		init();

		for(char c : str){
			if (c == '(') 
				op_stack.push({ c, 0 });

			else if (c == ')') {
				while (op_stack.top().first != '(') 
					func();
				op_stack.pop();
			}
			
			else if (c == '*' || c == '+' || c == '-') {
				int prio;
				if (c == '+' || c == '-') prio = 1;
				else if (c == '*') prio = 2;

				// 연산자 우선 순위 낮은게 top으로 올 때까지 계산
				while (!op_stack.empty() && prio <= op_stack.top().second) 
					func();

				// 스택에 연산자 push
				op_stack.push({ c, prio });
			}

			if (c == '{') continue;
			else if (c >= 'A' && c <= 'Z') temp += c;
			else if (c == '}') {
				str_stack.push(temp);
				temp = "";
			}
		}

		while (!op_stack.empty())
			func();
		cout << '{' << str_stack.top() << '}' << '\n';
	}
}

void init() {
	while (!str_stack.empty())
		str_stack.pop();
	while (!op_stack.empty())
		op_stack.pop();
}