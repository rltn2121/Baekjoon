#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int a, p;
bool found = false;
int power(int n, int p) {
	if (p == 0)
		return 1;
	if (p == 1)
		return n;
	return n * (power(n, p - 1));
}

int calculate(int n) {
	int ret = 0;
	while (n > 0) {
		ret += power(n % 10, p);
		n /= 10;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> p;
	int idx = 0;
	m.insert({ a, idx++});
	while (!found) {
		a = calculate(a);
		if (m.find(a) != m.end())
			found = true;
		else
			m.insert({a,idx++});
	}
	auto it = m.find(a);
	cout << it->second << endl;
}