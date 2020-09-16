#include <iostream>
#define rep(i,n) for(int i = 0; i<n; i++)
using namespace std;
int arr1[1000000];
int arr2[1000000];
int result[2000000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep(i, n)
		cin >> arr1[i];
	rep(i, m)
		cin >> arr2[i];

	int i = 0, j = 0, idx = 0;
	while (i < n && j < m) {
		if (arr1[i] > arr2[j])
			result[idx++] = arr2[j++];
		else
			result[idx++] = arr1[i++];
	}
	if (i == n) {
		while (j < m)
			result[idx++] = arr2[j++];
	}
	else
		while (i < n)
			result[idx++] = arr1[i++];

	rep(i, idx)
		cout << result[i] << ' ';
}