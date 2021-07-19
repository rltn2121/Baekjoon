#include <iostream>
#include <algorithm>
using namespace std;
int cnt0, cnt1;
int main() {
	string str;
	cin >> str;
	char cur = str[0];
	if (cur == '0')
		cnt0++;
	else
		cnt1++;
	for (char c : str) {
		if (cur != c) {
			if (c == '0')
				cnt0++;
			else
				cnt1++;
			cur = c;
		}
	}
	cout << min(cnt0, cnt1);
}