#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<int> s;
	int k;
	cin >> k;
	while (k--) {
		int a;
		cin >> a;
		if (a == 0)	{	
			if (s.empty())
				continue;
			s.pop();
		}
		else
			s.push(a);
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum << endl;
}