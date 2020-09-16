#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > v;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	v.reserve(t);
	while (t--) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v)
		cout << i.first << ' ' << i.second << '\n';

}