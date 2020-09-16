#include <iostream>
using namespace std;
int main() {
	size_t count = 0;
	cin >> count;

	int *arr = new int[count];
	int sum = 0;
	for (size_t i = 0; i < count; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	cout <<  sum - count + 1<< endl;
}