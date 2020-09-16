#include <iostream>
#include <string>
using namespace std;
int main() {
	int arr[8];
	string a;
	for (int i = 0; i < 8; i++)
		cin >> arr[i];

	if (arr[0] == 1) {
		for (int i = 0; i < 7; i++) {
			if (arr[i + 1] != arr[i] + 1) {
				a = "mixed";
				break;
			}
		}
		if (a.empty())
			a = "ascending";
	}
	else if (arr[0] == 8) {
		for (int i = 0; i < 7; i++) {
			if (arr[i + 1] != arr[i] - 1) {
				a = "mixed";
				break;
			}
		}
		if (a.empty())
			a = "descending";
	}
	else
		a = "mixed";
	cout << a << '\n';
}