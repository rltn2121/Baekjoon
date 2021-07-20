#include <iostream>
using namespace std;
int n, i, arr[1000001];
int main() {
	arr[1] = 1;
	arr[2] = 2;
	for (i = 3;i < 1000001;i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	cin >> n;
	cout << arr[n];
}