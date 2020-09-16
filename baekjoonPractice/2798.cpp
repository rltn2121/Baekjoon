#include <iostream>
using namespace std;
int arr[100];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	int max = 0;
	if (n == 3)
		cout << arr[0] + arr[1] + arr[2] << endl;
	else
	{
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					if (max < arr[i] + arr[j] + arr[k] && arr[i] + arr[j] + arr[k] <= m) {
						max = arr[i] + arr[j] + arr[k];
						if (max == m)
							break;
					}
				}
			}
		}
		cout << max << endl;
	}
}