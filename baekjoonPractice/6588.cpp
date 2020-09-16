#include <iostream>
#include <set>
using namespace std;
int arr[1000000];
set<int> prime;
void initEratos() {
	arr[1] = 1;
	for (int i = 2; i < 999998; i++) {
		if (arr[i] == 1)
			continue;
		prime.insert(i);
		for (int j = 2 * i; j < 1000000; j += i) 
			arr[j] = 1;
	}
}
bool isPrime(int n) {
	auto it = prime.find(n);
	if (it != prime.end())
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	initEratos();
	int n;
	cin >> n;
	
	while (n != 0) {
		for (int i : prime) {
			if (i > n / 2)
				break;

			if (isPrime(n - i))	{
				cout << n << " = "<< i << " + " << n - i << '\n';
				break;
			}
		}
		cin >> n;
	}
	
}