#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pr;
bool cmp(pr& a, pr& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	vector<pr> v;
	while (t--) {
		pr p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), cmp);
	for (pr p : v)
		cout << p.first << ' ' << p.second << '\n';
}