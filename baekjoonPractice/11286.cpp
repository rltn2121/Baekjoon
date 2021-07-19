#include <iostream>
#include <queue>
using namespace std;
struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};
priority_queue<int, vector<int>, cmp > pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int nA
	cin >> n;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty())	
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}