#include <iostream>
#include <algorithm>
#include <vector>
#define pr pair<int, int>
#define fst first
#define snd second
using namespace std;
vector<pr> v;
bool cmp(pr& a, pr& b) {
	if (a.snd == b.snd)
		return a.fst < b.fst;
	return a.snd < b.snd;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t; 
	while (t--) {
		pr p;
		cin >> p.fst >> p.snd;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), cmp);
	int cnt = 0;
	int lastTime = -1;
	for (auto it : v) {
		if (it.fst >= lastTime) {
			lastTime = it.snd;
			cnt++;
		}
	}
	cout << cnt << '\n';
}