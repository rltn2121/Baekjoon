#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
int main() {
	int n, x, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;

		if (m.find(x) == m.end())
			m.insert({ x, 1 });
		else
			m[x]++;

		if ((m.find(x + 1) == m.end()) || m[x + 1] == 0)
			cnt++;
		else
			m[x + 1]--;
	}
	cout << cnt;
}