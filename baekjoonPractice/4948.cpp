#include <iostream>
using namespace std;
int arr[246913];
void eratos() {
	int n = 123456 * 2;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 1)
			continue;
		for (int j = i * 2; j <= n; j += i)
			arr[j] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	eratos();
	int n;
	cin >> n;
	while (n != 0) {
		int count = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == 0)
				count++;
		}
		cout << count << endl;
		cin >> n;
	}
}