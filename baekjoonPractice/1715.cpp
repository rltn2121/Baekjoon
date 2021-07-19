#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int n, x, ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> x;
		q.push(x);
	}
	while (q.size()!=1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		int c = a + b;
		ans += c;
		q.push(c);
	}
	cout << ans;
}