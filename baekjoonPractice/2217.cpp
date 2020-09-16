#include <iostream>
#include <algorithm>

// 큰값->작은값 : 오답
// 작은값->큰값 : 정답
using namespace std;

int arr[100001] = { 0, };
int n;

bool cmp(int a, int b) {
	return a < b;
}

int func() {
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] * (n-i) > max)
			max = arr[i] * (n-i);
	}
	return max;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, cmp);

	cout << func();
}