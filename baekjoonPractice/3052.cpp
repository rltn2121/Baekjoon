#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	int arr[42] = { 0, };
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		if (arr[x % 42] == 0) {
			arr[x % 42]++;
			count++;
		}
	}
	cout << count << '\n';
}