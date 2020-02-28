#include <iostream>
#include <string>
using namespace std;
string str;
string arr[100001];
int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	
	for (int i = 0; i < n; i++) {
		cin >> str;
		arr[i] = str;
	}

	while (m--) {
		cin >> str;
		if (isdigit(str[0])) {
			int x = 0;
			int position = 1;
			for (int i = str.length() - 1; i >= 0; i--) {
				x += ((int)str[i] - 48) * position;
				position *= 10;
			}
			cout << arr[x - 1] << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (arr[i] == str)
					cout << i + 1 << endl;
			}
		}
	}

	
}