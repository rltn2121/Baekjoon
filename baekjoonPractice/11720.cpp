#include <iostream>
using namespace std;
int main() {
	int size;
	int sum = 0;
	scanf_s("%d", &size);
	int *arr = new int[size];
	for (int i = 0; i<size; i++) {
		scanf_s("%1d", &arr[i]);
		sum += arr[i];
	}
	printf("%d\n", sum);
}