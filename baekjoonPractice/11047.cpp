#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	int n;
	long long k;
	
	cin >> n >> k;
	long long temp = k;
	long long arr[10];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, compare);

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (k == 0)
			break;

		while (k - arr[i] >= 0) {
			k -= arr[i];
			count++;
		}

	}

	int count2 = 0;
	for (int i = 0; i < n; i++) {
		if (temp % arr[i] != 0)
			continue;

		while (temp - arr[i] >= 0) {
			temp -= arr[i];
			//cout << "k: " << temp << endl;
			count2++;
		}
		break;

	}
	//cout << count << ' ' << count2 << endl;
	cout << (count < count2 ? count : count2) << endl;
}