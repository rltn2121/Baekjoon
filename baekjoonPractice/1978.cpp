//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int isPrime(int n) {
//	if (n == 0 || n==1)
//		return 0;
//	if (n == 2)
//		return 1;
//	double squareroot = ceil(sqrt(n));
//	for (int i = 2; i <= squareroot; i++) {
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	
//	int n;
//	cin >> n;
//
//	int count = 0;
//	while (n--) {
//		int p;
//		cin >> p;
//		if (isPrime(p))
//			count++;
//	}
//	cout << count << endl;
//}