#include <iostream>
#define ll long long
using namespace std;
int n;
const ll DIV = 1e9 + 9;
ll arr[33334];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	arr[1] = 0;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) 
		arr[i] = 3 * arr[i - 1] % DIV;
	cout << arr[n];
}