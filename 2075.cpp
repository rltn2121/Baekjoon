#include <iostream>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;
int n;
map<ll, int> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	rep(i, n) {
		rep(j, n) {
			int x;
			cin >> x;
			m.insert({ x,1 });
			if (m.size()>n) {
				m.erase((*m.begin()).first);
			}
		}
	}
	auto it = m.end();
	while (n--)
		it--;
	cout << (*it).first;
}