#include <iostream>
using namespace std;
/*
	약수가 아닌 배수 기준으로 생각
	n = 1,000,000
	2: 2 4 6 ... 999998 1000000		-> 2: 50만개 포함됨
	3: 3 6 9 ... 999996 999999		-> 3: 33만개 포함됨
	4: 4 8 12 ... 999996 1000000	-> 4: 25만개 포함됨
*/
int main() {
	long long n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		ans += (n / i)*i;
	
	cout << ans;
}