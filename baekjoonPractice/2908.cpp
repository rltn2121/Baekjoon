#include <iostream>
using namespace std;
int main() {
	int arr1[3];
	for (int i = 0; i < 3; i++) {
		scanf_s("%1d", &arr1[i]);
	}

	int arr2[3];
	for (int i = 0; i < 3; i++) {
		scanf_s("%1d", &arr2[i]);
	}
	int num1 = arr1[2] * 100 + arr1[1] * 10 + arr1[0];
	int num2 = arr2[2] * 100 + arr2[1] * 10 + arr2[0];

	cout << ((num1 > num2) ? num1 : num2);
	

}