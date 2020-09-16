#include <iostream>
using namespace std;
bool arr[1000];
void initArr(bool* arr) {
	for (int i = 123; i <= 987; i++) {
		int temp = i;
		int a = temp % 10;
		temp /= 10;
		int b = temp % 10;
		temp /= 10;
		int c = temp;
		if (a == b || b == c || c == a)
			arr[i] = 1;
		if (a == 0 || b == 0 || c == 0)
			arr[i] = 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	initArr(arr);
	int t;
	cin >> t;
	while (t--) {
		string str;
		int s, b;
		cin >> str >> s >> b;

		for (int i = 123; i <= 987; i++) {
			if (arr[i] == 1)
				continue;
			string temp = "000";
			int n = i;
			temp[2] = (n % 10)+48;
			n /= 10;
			temp[1] = (n % 10) + 48;
			n /= 10;
			temp[0] = n+48;
			int s_cnt = 0, b_cnt = 0;
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (str[j] == temp[k]) {
						if (j == k)
							s_cnt++;
						else
							b_cnt++;
					}
				}
			}
			if (s != s_cnt || b != b_cnt)
				arr[i] = 1;
		}

	}
	int cnt = 0;
	for (int i = 123; i <= 987; i++) {
		if (arr[i]==0)
			cnt++;
	}
	cout << cnt << '\n';
}