#include <iostream>
using namespace std;
int fact(int x) {
	if (x == 0) return 1;
	return x*fact(x - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x;
	cin >> x;
	cout << fact(x);
}