#include <iostream>
using namespace std;
int main() {
	int n;
	scanf_s("%d",&n);
	int *student = new int[n];
	int *apple = new int[n];
	int sum = 0;

	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &student[i], &apple[i]);
		sum +=  apple[i] %  student[i];
	}

	cout << sum << endl;
	delete[] student;
	delete[] apple;
}