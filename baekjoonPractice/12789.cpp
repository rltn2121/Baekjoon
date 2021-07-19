#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int next = 1;
	int x;
	string str = "Nice";
	cin >> n;
	for (int i = 0; i < n; i++) {
		while (!s.empty()) {
			if (s.top() != next)
				break;
			s.pop();
			next++;
			continue;
		}
		cin >> x;
		if (x == next) {
			next++;
			continue;
		}
		else
			s.push(x);
	}
	// 스택 안비었으면 대기열에 사람 있는거
	while (!s.empty()) {
		if (s.top() != next) {
			str = "Sad";
			break;
		}
		s.pop();
		next++;
	}
	cout << str;
}