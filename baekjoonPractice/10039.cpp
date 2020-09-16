#include <iostream>
using namespace std;
int main() {
	int arr[5];
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr[i]);
		if (arr[i] < 40)
			arr[i] = 40;
		total += arr[i];
		
	}
	printf("%d\n", total / 5);
	
}