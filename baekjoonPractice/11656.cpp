#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<string> s;
	string str;
	cin >> str;
	int len = str.length();
	/*for (int i = 0; i < len; i++) {
		string temp = str.substr(i, len-i);
		s.insert(temp);
	}*/
	string temp[1000];
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++)
			temp[i] += str[j];
		s.insert(temp[i]);
	}

	for (auto i : s)
		cout << i << endl;
}