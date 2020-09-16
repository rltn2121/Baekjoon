#include <iostream>
using namespace std;
string str[50];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];

	string result = str[0];
	for (size_t i = 0; i < str[0].length(); i++) {
		for (int j = 1; j < n; j++) {
			if (result[i] != str[j][i])
			{
				result[i] = '?';
				break;
			}
		}
	}
	cout << result << endl;
}