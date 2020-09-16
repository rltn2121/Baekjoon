#include <iostream>
using namespace std;

int arr[6] = { 500, 100, 50, 10, 5, 1 };
int main() {
	int n;
	cin >> n;
	int x = 1000 - n;
	int count = 0;
	int index = 0;
	while (true) {
		if (x == 0) {
			cout << count << endl;
			break;
		}
		if (x - arr[index] >= 0) {
			x -= arr[index];
			count++;
		}
		else
			index++;
	}

}