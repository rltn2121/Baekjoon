#include <iostream>	
#include <algorithm>
using namespace std;
int arr[1000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	int sum = arr[0];
	for (int i = 1; i < n; i++)	{
		arr[i] += arr[i - 1];
		sum += arr[i];
	}
	cout << sum << endl;
}
