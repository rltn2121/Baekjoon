#include <iostream>
#define ll long long
using namespace std;
int n;
ll arr[91];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	cout << arr[n];
}