#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	cin >> input;
	int num = 666;
	int cnt = 0;
	string str = "";
	while (true) {
		// ���� -> ���ڿ�
		str = to_string(num);
		// ���ڿ��� 666 ����?
		if (str.find("666") != -1) {
			cnt++;
			if (cnt == input)
				break;
		}
		num++;
	}
	cout << num;
}