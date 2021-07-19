#include <iostream>
using namespace std;
int arr[2000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		int x;
		cin >> x;
		arr[x+1000000] = 1;
	}

	for (int i = 2000000; i >= 0; i--) {
		if (arr[i]==1)
			cout << i-1000000 << '\n';
	}
}