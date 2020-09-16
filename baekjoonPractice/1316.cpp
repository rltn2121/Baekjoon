#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int count = 0;
	int n;
	cin >> n;
	while (n--) {
		bool flag = true;
		bool arr[26] = { 0, };

		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			if (i == 0) {
				arr[(int)str[i] - 97] = true;
				continue;
			}

			if (str[i] == str[i - 1])
				continue;

			if (arr[(int)str[i] - 97] == true) {
				flag = false;
				break;
			}

			arr[(int)str[i] - 97] = true;
		}
		if (flag)
			count++;
	}
	cout << count << endl;
}