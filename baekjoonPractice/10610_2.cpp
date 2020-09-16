#include <iostream>
#include <string>
using namespace std;
int arr[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long sum = 0;
	string str;
	cin >> str;
	for (char c : str) {	
		sum += c - '0';
		arr[c - '0']++;
	}
	if (!arr[0] || sum % 3 != 0)
		cout << -1;
	else {
		int idx = 9;
		while (idx >= 0) {
			while (arr[idx] > 0) {
				cout << idx;
				arr[idx]--;
			}
			idx--;
		}
	}
}