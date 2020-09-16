#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int arr[10001];
int n;
int result = 0;
stack<int> s;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (arr[i] <= 0)
			q.push(arr[i]);
		else
			s.push(arr[i]);
	}
	int a=0, b=0;
	while (!q.empty()) {
		a = q.front();
		q.pop();
		if (q.empty())
			break;
		b = q.front();
		q.pop();
		result += a * b;
		a = 0;
		b = 0;
	}
	if (a != 0)
		result += a;
	a = 0;
	b = 0;
	while (!s.empty()) {
		a = s.top();
		s.pop();
		if (s.empty())
			break;
		b = s.top();
		s.pop();

		if (a == 1 || b == 1)
			result += a + b;
		else
			result += a * b;
		a = 0;
		b = 0;
	}
	if (a != 0)
		result += a;
	cout << result << '\n';
}