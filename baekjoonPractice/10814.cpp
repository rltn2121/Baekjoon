//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <map>
//using namespace std;
//multimap<int, string> m;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		string str;
//		cin >> n >> str;
//		m.insert({ n, str });
//	}
//	
//	for (auto it : m)
//		cout << it.first << ' ' << it.second << '\n';
//}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, string> pr;
bool cmp(const pr& a, const pr& b) {
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	vector<pr> v;
	v.reserve(t);
	while (t--) {
		pr p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	stable_sort(v.begin(), v.end(), cmp);
	for (auto it : v)
		cout << it.first << ' ' << it.second << '\n';
}