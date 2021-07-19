#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str[20000];
bool cmp(const string& a, const string& b) {
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> str[i];
	sort(str, str + n, cmp);

	cout << str[0] << '\n';
	for (int i = 1; i < n; i++) {
		if (str[i] == str[i - 1])
			continue;
		cout << str[i] << '\n';
	}
}