#include <iostream>
using namespace std;
long long arr[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		int x;
		cin >> x;
		arr[x]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (arr[i] > 0) {
			cout << i << '\n';
			arr[i]--;
		}
	}
}