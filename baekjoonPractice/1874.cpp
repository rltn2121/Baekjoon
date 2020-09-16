#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<int> s;
	queue<char> c;
	int arr[100001];
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}

	int idx = 1;
	int i = 0;
	while (i<n)	{
		s.push(++i); c.push('+');

		while (!s.empty() && arr[idx] == s.top()) {
			c.push('-'); s.pop();
			idx++;
		}
	}

	if (!s.empty())
		cout << "NO" << '\n';
	else
		while (!c.empty()) {
			cout << c.front() << '\n';
			c.pop();
		}
}