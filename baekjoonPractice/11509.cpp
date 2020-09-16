#include <iostream>
#include <map>
#include <set>
using namespace std;
multimap<int, int> m;
multiset<int, greater<int> > s;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		m.insert(make_pair( a,i ));
		s.insert(a);
	}



	int cnt = 1;


	int h = *s.begin();
	s.erase(s.begin());
	while (true) {
		auto it = m.find(h);
	}

	cout << cnt << '\n';
}