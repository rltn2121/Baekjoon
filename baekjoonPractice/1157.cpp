#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int arr[26] = { 0, };
	string str;
	cin >> str;

	
	for (char c : str) {
		if (c >= 97)
			c -= 32;
		arr[(int)c - 65]++;
	}

	int val_max = arr[0];
	int idx_max = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > val_max) {
			idx_max = i;
			val_max = arr[i];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (i == idx_max)
			continue;

		if (arr[i] == val_max)	{
			cout << '?' << '\n';
			return 0;
		}
	}
	
	cout << char(idx_max + 65) << '\n';
}