#include <iostream>
using namespace std;
int arr[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	
	int idx = n - 1;
	int cnt = 0;
	while (k > 0) {
		if (k - arr[idx] < 0)
			idx--;
		else {
			k -= arr[idx];
			cnt++;
		}
	}
	cout << cnt << '\n';
}