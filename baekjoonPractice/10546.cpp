#define rep(i,n) for(int i=0;i<n;i++)
#include <iostream>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, int> mp;
	int n;
	cin >> n;
	
	string name;
	rep(i, n) {
		cin >> name;
		if (mp.count(name) > 0)
			mp[name]++;
		else
			mp.insert(make_pair(name, 1));
	}

	rep(i, n - 1) {
		cin >> name;
		if (mp[name] > 1)
			mp[name]--;
		else
			mp.erase(name);
	}
	cout << mp.begin()->first;
}