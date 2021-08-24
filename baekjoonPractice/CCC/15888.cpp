#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int a, b, c;
bool isugeon[101];
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;

	// 2의 배수 찾기
	int temp = 1;
	while (temp <= 100) {
		isugeon[temp] = 1;
		temp <<= 1;
	}
	// 판별식
	if (b * b - 4 * a * c <= 0) {
		cout << "둘다틀렸근";
		return 0;
	}

	// 서로 다른 두 근인데 정수 근이 아니면
	if (b % a != 0 || c % a != 0) {
		cout << "둘다틀렸근";
		return 0;
	}

	// a를 1로 변경
	b /= a;
	c /= a;
	a = 1;

	// 1. c의 약수 구하기
	for (int i = 1; i <= abs(c); i++) {
		if (c % i == 0) {
			v.push_back(i);
			v.push_back(-i);
		}
	}

	for (int i : v) {
		int x = i;
		int y = c / x;
		if (x + y == -b) {
			if (x>=2&&y>=2&&isugeon[x] && isugeon[y]) {
				cout << "이수근";
				return 0;
			}
			else {
				cout << "정수근";
				return 0;
			}
		}
	}
	cout << "둘다틀렸근";
}