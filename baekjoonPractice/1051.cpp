#include <iostream>
using namespace std;
char arr[51][51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	
	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-1; j++) {
			for (int k = j+1; k < m; k++) {
				if (arr[i][j] == arr[i][k]) {
					int diff = k - j;
					if (i + diff >= n)
						continue;
					if (arr[i + diff][j] == arr[i][j] && arr[i + diff][k] == arr[i][k])
						max = (max > diff ? max : diff);
					
				}
			}
		}
	}
	if (max == -1)
		cout << 1 << endl;
	else
		cout << (max+1) * (max+1) << endl;
}