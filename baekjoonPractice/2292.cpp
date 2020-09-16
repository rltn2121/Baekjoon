#include <iostream>
using namespace std;
long long arr[20001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long sum = 0;
	for (int i = 0; i < 20000; i++) {
		sum += i;
		arr[i] = sum*6+1;
	}

	
	long long n;
	cin >> n;
	for (int i = 0; i < 20000; i++) {
		if (n <= arr[i])	{
			cout << i+1 << '\n';
			break;
		}
	}
}