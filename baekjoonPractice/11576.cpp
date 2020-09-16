#include <iostream>
#include <stack>
using namespace std;
int power(int x, int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return x;

	return x * power(x, n - 1);
}
int arr[25];
int main() {

	int a, b;
	cin >> a >> b;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> arr[i];
	
	int num = 0;
	int temp = m;
	for (int i = 0; i < m; i++) 
		num += arr[i] * power(a, --temp);
	
	stack<int> s;
	while (num != 0) {
		s.push(num % b);
		num /= b;
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}



