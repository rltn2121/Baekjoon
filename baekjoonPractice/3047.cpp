#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);

	char c1, c2, c3;
	cin >> c1 >> c2 >> c3;

	int n1 = int(c1);
	int n2 = int(c2);
	int n3 = int(c3);

	int max = (n1 > n2 ? (n1 > n3 ? n1 : n3) : (n2 > n3 ? n2 : n3));
	int min = (n1 < n2 ? (n1 < n3 ? n1 : n3) : (n2 < n3 ? n2 : n3));

	
	if ((int)c1 == max)
		cout << arr[2] << ' ';
	else if ((int)c1 == min)
		cout << arr[0] << ' ';
	else
		cout << arr[1] << ' ';

	if ((int)c2 == max)
		cout << arr[2] << ' ';
	else if ((int)c2 == min)
		cout << arr[0] << ' ';
	else
		cout << arr[1] << ' ';

	if ((int)c3 == max)
		cout << arr[2] << ' ';
	else if ((int)c3 == min)
		cout << arr[0] << ' ';
	else
		cout << arr[1] << ' ';
}