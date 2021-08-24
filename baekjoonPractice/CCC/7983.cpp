#include <iostream>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int, int>
using namespace std;
priority_queue<pii> pq;
int n;
pii p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		cin >> p.second >> p.first;
		pq.push(p);
	}
	int empty_day = 1e9;
	while (!pq.empty()) {
		pii now = pq.top(); pq.pop();
		int deadline = now.first;
		int need = now.second;

		if (deadline > empty_day)
			deadline = empty_day;
		empty_day = deadline - need;
	}
	cout << empty_day;
}