#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long arr[5001];
	int sum = 0;
	for (int i = 1; i < 5001; i++) {
		sum += i;
		arr[i] = sum;
	}

	int n;
	long long idx;
	cin >> n;

	for (int i = 0; i < 5001; i++) {
		if (n <= arr[i]) {
			idx = i;
			break;
		}
	}
	int sum_of_frac = idx + 1;

	int denominator = 0;
	int numerator = 0;
	if (sum_of_frac % 2 == 1) {
		numerator = arr[idx] - n + 1;
		denominator = sum_of_frac - numerator;
	}
	else {
		denominator = arr[idx] - n + 1;
		numerator = sum_of_frac - denominator;
	}

	cout << denominator << '/' << numerator << endl;
}