#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string str1, str2;
		cin >> str1;
		cin.ignore();
		cin >> str2;

		int cnt = 0;
		for (int i = 0; i < str1.length();i++) {
			if (str1[i] != str2[i])
				cnt++;
		}
		cout << "Hamming distance is " << cnt << ".\n";
	}
}