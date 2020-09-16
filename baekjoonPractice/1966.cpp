#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		multiset<int, greater<int> > s;
		queue<pair<int, int> > q;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int priority;
			cin >> priority;
			q.push(make_pair(i, priority));
			s.insert(priority);
		}

		int idx = 1;
		while (!q.empty()) {
			pair<int, int> temp = q.front();
			q.pop();
			if (temp.second == *s.begin()) {
				if (temp.first == m) {
					cout << idx << '\n';
					break;
				}
				idx++;
				s.erase(s.begin());
			}
			else
				q.push(temp);
		}
	}
}