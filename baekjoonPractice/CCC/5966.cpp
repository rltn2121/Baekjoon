#include <iostream>
#include <stack>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
stack<char> s;
int t,n;
string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		bool flag = 1;
		cin >> n >> str;

		for (char c : str) {
			if (c == '>') s.push(c);
			else {
				if (s.empty()) {
					flag = 0;
					break;
				}
				else s.pop();
			}
		}
		if (!s.empty()) {
			flag = 0;
			while (!s.empty())
				s.pop();
		}
		cout << (flag ? "legal" : "illegal") << '\n';
	}
}