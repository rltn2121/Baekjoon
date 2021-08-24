#include <iostream>
#include <algorithm>
using namespace std;
int sum;
bool cmp(char a, char b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	sort(str.begin(), str.end(), cmp);
	
	if (str[str.size() - 1] != '0') {
		cout << -1;
		return 0;
	}
	for (char c : str)
		sum += (c - '0');
	if (sum % 3 != 0) {
		cout << -1;
		return 0;
	}
	cout << str;
}