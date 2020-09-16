#include <iostream>
#include <string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int total = 0;
		int bonus = 0;
		string oxStr;
		cin >> oxStr;

		for (int i = 0; i < oxStr.length(); i++) {
			if (oxStr[i] == 'O') {
				total += ++bonus;
			}
			else
				bonus = 0;
		}
		cout << total << endl;
	}
}