#include <iostream>
using namespace std;
typedef long long ull;
pair<ull, ull> count(int n) {
	pair<ull, ull> ret;
	
	for (ull i = 2; i <= n; i *= 2)
		ret.first += n / i;
	
	for (ull i = 5; i <= n; i *= 5)
		ret.second += n / i;
	return ret;
}
int main() {
	long long n, m;
	cin >> n >> m;
	long long k = n - m;

	pair<ull, ull> a = count(n);
	pair<ull, ull> b = count(m);
	pair<ull, ull> c = count(k);
	
	long long total2, total5;

	total2 = a.first - b.first - c.first;
	total5 = a.second - b.second - c.second;
	cout << (total2 < total5 ? total2 : total5);
}