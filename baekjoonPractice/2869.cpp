#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long a, b, v = 0;
	int count = 1;
	cin >> a >> b >> v;

	long long temp = v - a;
	long long up = a - b;
	count = temp / up;
	if (temp % up != 0)
		count++;
	
	cout << count + 1 << '\n';
}