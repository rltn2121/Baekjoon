#include <iostream>
using namespace std;

char arr[30][30];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout << arr[0][0] << endl;
	string a, b;
	cin >> a >> b;
	int i = 0, j = 0;
	bool find = false;
	for (i = 0; i < a.length(); i++) {
		for (j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				find = true;
				break;
			}
		}
		if (find)
			break;
	}

	for(int k = 0; k<a.length(); k++)
		arr[j][k] = a[k];

	for (int k = 0; k < b.length(); k++) {
		arr[k][i] = b[k];
	}

	for (i = 0; i < b.length(); i++) {
		for (j = 0; j < a.length(); j++) 
			cout << (arr[i][j]==NULL ? '.' : arr[i][j]);
		cout << endl;
	}
}