#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	stack<int> stick;
	int count = 0;
	int sum = 0;

	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '(')
		{
			stick.push(++count);
			cout << "���� ���� ����: " << count << endl;
		}
		else
		{
			if (str[i - 1] == '(')
			{
				cout << "������ on" << endl;
				int top = stick.top() - 1;
				cout << "�����丷 ����: " << top << endl;
				sum += top;
				cout << "sum: " << sum << endl;
				count--;
			}
			else
			{
				sum++;
				cout << "sum: " << sum << endl;
				stick.pop();
				count--;
			}
		}
	}
	cout << sum << endl;


}