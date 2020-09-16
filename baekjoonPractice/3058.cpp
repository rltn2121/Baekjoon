#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	int arr[7];
	for (int i = 0; i < n; i++) {
		int sum = 0;
		int min = 99999;
		for (int j = 0; j < 7; j++)
		{
			cin >> arr[j];
			if (arr[j] % 2 == 0)
			{
				sum += arr[j];
				if (arr[j] < min)
					min = arr[j];
			}
			
		}
		cout << sum << ' ' << min << '\n';
	}
}