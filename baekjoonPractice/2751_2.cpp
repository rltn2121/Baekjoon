#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	vector<int> v;
	v.reserve(t);
	while (t--) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i : v)
		cout << i << '\n';
}