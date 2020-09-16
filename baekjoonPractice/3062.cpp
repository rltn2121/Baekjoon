#include <iostream>
#include <cmath>
using namespace std;

int square(int count) {
	int ret = 1;
	for (int i = 0; i < count; i++)
		ret *= 10;
	return ret;
}
bool isSymmetric(int n) {
	bool symmetric = true;

	int tmp = n;
	int position = 0;
	//  자리수 (position) 구하기
	while (tmp > 0) {
		tmp /= 10;
		position++;
	}
	// 대칭 확인
	while (n>10)
	{
		int startNum = n / square(--position);
		int endNum = n % 10;
		if (startNum != endNum) {
			symmetric = false;
			break;
		}

		else {
			n -= (startNum*square(position));
			n /= 10;
			position--;
		}
	}
	return symmetric;
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		int num;
		cin >> num;

		int tmp = num;
		int reverse[6];
		int position = 0;
		while (tmp > 0) {
			reverse[position++] = tmp % 10;
			tmp /= 10;
		}

		int temp = position;
		int reverseNum = 0;
		for (int i = 0; i < position; i++) {
			reverseNum += reverse[i] * square(--temp);
		}

		int sum = num + reverseNum;
		
		cout << (isSymmetric(sum) ? ("YES\n") : ("NO\n"));
	}
}