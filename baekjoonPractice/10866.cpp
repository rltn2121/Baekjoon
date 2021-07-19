#include <iostream>
#include <deque>
using namespace std;
deque<int> deq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string str;
	while (t--) {
		cin >> str;
		if (str == "push_front") {
			int x;
			cin >> x;
			deq.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			deq.push_back(x);
		}

		else if (str == "pop_front") {
			if (deq.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << deq.front() << '\n';
			deq.pop_front();
		}
		else if (str == "pop_back") {
			if (deq.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << deq[deq.size()-1] << '\n';
			deq.pop_back();
		}
		else if (str == "size") 
			cout <<deq.size() << '\n';

		else if (str == "empty")
			cout << deq.empty() << '\n';

		else if (str == "front") {
			if (deq.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << deq.front() << '\n';
		}
		else if (str == "back") {
			if (deq.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << deq[deq.size() - 1] << '\n';
		}
		
	}
}