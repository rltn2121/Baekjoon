#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[7];
	int min = 999999;
	int sum = 0;
	for (int i = 0; i < 7; i++)	{
		cin >> arr[i];
		if (arr[i] % 2 == 1) {
			sum += arr[i];
			if (arr[i] < min)
				min = arr[i];
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << '\n' << min;
}