#include <iostream>
using namespace std;
int arr[1000001];
void eratos(int n) {
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 1)
			continue;

		for (int j = 2; i*j<=n; j++) 
			arr[i*j] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	eratos(n);
	for (int i = m; i <= n; i++) {
		if (arr[i] == 0)
			cout << i << '\n';
	}
}