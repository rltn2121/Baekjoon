#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
int cnt;
string str;
int main() {
	while (getline(cin, str)) {
		m[str]++;
		cnt++;
	}
	
	
	for (auto it : m) {
		cout << it.first;
		printf(" %.4f\n",(double)it.second * 100 / cnt);
		
	}
}