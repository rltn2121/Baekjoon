#include <iostream>
using namespace std;
int a, b, cnt, last;
int main() {
	cin >> a >> b;
	
	// 같으면 안됨 (b = -1 -> while 안들어감)
	if (a == b) 
		b = -1;
	
	// b == a 이거나 b < a 이면 벗어남
	while (b>a) {
		last = b % 10;
		// 마지막 숫자가 3, 5, 7, 9 될 수 없음
		if (last > 1 && last % 2 == 1) break;

		// 마지막 숫자가 1이면 1 제거
		// 마지막 숫자가 2의 배수이면 2로 나눔
		last == 1 ? b /= 10 : b /= 2;
		cnt++;
	}
	cout << (b == a ? cnt + 1 : -1);
}