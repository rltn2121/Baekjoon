#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool arr[1000];
void initArr() {
	memset(arr, true, sizeof(arr));
	for (int i = 123; i <= 987; i++) {
		string str = to_string(i);

		if (str[0] -48== 0 || str[1] - 48 == 0 || str[2] - 48 == 0)
			arr[i] = false;
		
		if (str[0] == str[1] || str[0] == str[2] || str[1] == str[2])
			arr[i] = false;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	initArr();

	int t;
	cin >> t;
	while (t--) {
		int n, strike, ball;
		cin >> n >> strike >> ball;

		for (int i = 123; i <= 987; i++) {
			if (!arr[i])
				continue;

			string str1 = to_string(i);
			string str2 = to_string(n);

			int s = 0, b = 0;
			
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (str1[j] == str2[k]) {
						if (j == k)
							s++;
						else
							b++;
					}
				}
			}
			if (strike != s || ball != b)
				arr[i] = false;
		}
	}

	int cnt = 0;
	for (int i = 123; i <= 987; i++) {
		if (arr[i] == true)
			cnt++;
	}
	cout << cnt;
}