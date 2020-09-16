#include <iostream>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	if (n == 1)
		cout << 1;
	else if(n == 2) {
		if (m >= 7)
			cout << 4;
		else
			cout << ((m -1)/ 2) + 1;
	}
	else {
		if (m <= 4)
			cout << m;
		else if (m < 7)
			cout << 4;
		else 
			cout << m - 2;
	}	
}