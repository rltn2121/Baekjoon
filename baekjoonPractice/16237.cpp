#include <iostream>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int arr[6], ans;
void func5();
void func4();
void func3();
void func2();
void func1();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	rep(i, 5)
		cin >> arr[i];

	func5();
	func4();
	func3();
	func2();
	func1();

	cout << ans;
}
void func5(){
	ans += arr[5];
	arr[5] = 0;
}
void func4(){
	ans += arr[4];
	arr[1] -= arr[4];
	arr[4] = 0;
}
void func3(){
	ans += arr[3];

	// 1. �� ����
	if (arr[3] == arr[2]) {
		arr[3] = 0;
		arr[2] = 0;
	}

	// 2. 3 ���� -> 1�� ä���
	else if (arr[3] > arr[2]) {
		arr[3] -= arr[2];
		arr[2] = 0;
		arr[1] -= (arr[3] * 2);
	}

	// 3. 2 ���� -> ��� ����
	else if (arr[3] < arr[2]) {
		arr[2] -= arr[3];
		arr[3] = 0;
	}
}
void func2(){
	if (arr[2] > 0) {
		// 2 ���� �� �ʿ��� ����
		int temp = (arr[2] + 1) / 2;
		ans += temp;


		// Ȧ�� ���� ������ �ϳ��� 3�� ���� �� ����
		if (arr[2] % 2 == 1) {
			arr[1] -= (temp-1);
			arr[1] -= 3;
		}
		// ¦�� ���� �ϳ��� ���� �� ����
		else
			arr[1] -= temp;
	}
}
void func1(){
	if (arr[1] > 0)
		ans += (((arr[1] - 1) / 5) + 1);
}