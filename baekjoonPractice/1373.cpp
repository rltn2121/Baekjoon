#include <iostream>
#include <string>
#include <stack>
using namespace std;
int arr[1000000];
int main() {
	string str;
	stack<int> s;
	cin >> str;
	if (str.length() == 1 && str[0] == '0')
		cout << 0 << endl;
	for (int i = 0; i < str.length(); i++)
		s.push((int)str[i] - 48);
	int idx = 0;
	while (!s.empty()) {
		arr[idx++] = s.top();
		s.pop();
	}
	int sum = 0;
	for (int i = 0; i < idx; i++) {
		if ((i + 1) % 3 == 1)
			sum += arr[i];
		else if ((i + 1) % 3 == 2)
			sum += arr[i] * 2;
		else {
			sum += arr[i] * 4;
			s.push(sum);
			sum = 0;
		}
	}
	if(sum != 0)
		s.push(sum);

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}	
}