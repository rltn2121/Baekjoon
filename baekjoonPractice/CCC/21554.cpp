#include <iostream>	
#include <stack>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pii pair<int, int>
using namespace std;
stack<int> s;
queue<pii> q;
int n, arr[101], cnt;
void func(int start, int end) {
	q.push({ start, end });
	for (int i = start; i <= end; i++) 
		s.push(arr[i]);
	
	for (int i = start; i <= end; i++) {
		arr[i] = s.top();
		s.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		cin >> arr[i];
	}

	rep(i, n) {
		if (arr[i] != i) {
			int start = i;
			int end = -1;
			for (int j = i + 1; j <= n;j++) {
				if (arr[j] == i) {
					end = j;
					break;
				}
			}
			func(start, end);
			cnt++;
		}
	}
	cout << cnt << '\n';
	while (!q.empty()) {
		cout << q.front().first << ' ' << q.front().second << '\n';
		q.pop();
	}
}