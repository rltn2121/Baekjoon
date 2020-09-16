#include <iostream>
using namespace std;

int position(int n) {
	int count = 1;
	while (n / 10 != 0) {
		n /= 10;
		count++;
	}
	return count;
}
int power(int n) {
	int a = 1;
	for (int i = 0; i < n; i++)
		a *= 10;
	return a;
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int result = a*b*c;
	int arr[10] = { 0 };
	cout <<"result:	"<< result << endl;
	int tmp = 0;
	while (result > 10) {
		tmp = result % 10;
		arr[tmp]++;
		cout << "arr[" << tmp << "]++" << endl;
		result /= 10;
		cout << "tmp: " << tmp << ", result: " << result << endl;
	}
	arr[result]++;

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	/*int arr[10];
	int position_result = position(result);
	int tmp = position_result;
	for (int i = 0; i < position_result; i++) {
		int powerI = power(--tmp);

		int quotient = result / powerI;
		if (i >= 1 && quotient == 0) {
			arr[i] = 0;
			continue;
		}
		int remainder = result % powerI;
		arr[i] = quotient;
		result = remainder;
	}

	int count[10] = { 0, };
	for (int i = 0; i < position_result; i++)
		count[arr[i]]++;
	for (int i = 0; i < 10; i++)
		cout << count[i] << '\n';*/
}