#include <iostream>
using namespace std;
long long getGCD(int a, int b) {
	if (b == 0)
		return a;
	return getGCD(b, a % b);

	/*while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;*/
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long arr[100];
		long long sum = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> arr[i];
		
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum+= getGCD(arr[i], arr[j]);
			}
		}
		cout << sum << endl;
	}
}