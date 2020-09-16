#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[9];
	int maxIndex = 0;
	int max = -99999;
	for (int i = 0; i < 9; i++)
	{
		int x;
		cin >> x;
		if (x > max) {
			max = x;
			maxIndex = i;
		}
	}
	cout << max << '\n' << maxIndex+1;
}