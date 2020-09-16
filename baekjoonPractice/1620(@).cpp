#include <iostream>
#include <map>
#include <string>
using namespace std;
string arr[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<string, int> monster;
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		monster.insert(make_pair(str,i));
		arr[i] = str;
	}
	
	while (m--) {
		string str;
		cin >> str;
		if ((int)str[0] < 65) {
			int idx = 0;
			int pos = 1;
			for (int i = str.length() - 1; i >= 0; i--)	{
				idx += ((int)str[i]-48) * pos;
				pos *= 10;
			}
			cout << arr[--idx] << '\n';
		}
		else {
			auto it = monster.find(str);
			cout << (*it).second+1 << '\n';
		}
	}
}