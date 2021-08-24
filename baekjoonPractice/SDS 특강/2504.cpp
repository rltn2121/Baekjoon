// Âü°í: https://soobarkbar.tistory.com/151
#include <iostream>
#include <stack>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
stack<char> s;
int temp = 1, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	rep(i, str.size()) {
		char c = str[i];
		if (c == '(') {
			s.push(c);
			temp *= 2;
		}
		else if (c == '[') {
			s.push(c);
			temp *= 3;
		}
		else if (c == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			s.pop();
			if(str[i-1] != ')' && str[i-1] != ']')
				ans += temp;
			temp /= 2;
		}

		else if (c == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			s.pop();
			if (str[i - 1] != ')' && str[i - 1] != ']')
				ans += temp;
			temp /= 3;
		}
	}

	if (!s.empty())
		cout << 0;
	else
		cout << ans;
}