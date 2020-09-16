#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int arr[10] = { 0, };
	string str;
	cin >> str;
	long long three = 0;

	for (char c : str) {
		arr[(int)c - 48]++;
		three += (int)c - 48;
	}

	if (arr[0] == 0 || three % 3 != 0)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 9; i >= 0; i--) {
		while (arr[i] != 0) {
			cout << i;
			arr[i]--;
		}
	}
}