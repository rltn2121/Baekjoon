#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pr;
vector<pr> v;
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
	while (t--) {
		pr p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto it : v) {
		cout << it.first << ' ' << it.second << '\n';
	}
	int cnt = 0;
	int lastTime = -1;
	for (auto it : v) {
		if (it.first >= lastTime) {
			lastTime = it.second;
			cnt++;
		}
	}
	cout << cnt << '\n';
}