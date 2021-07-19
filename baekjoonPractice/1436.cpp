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
		// 정수 -> 문자열
		str = to_string(num);
		// 문자열에 666 포함?
		if (str.find("666") != -1) {
			cnt++;
			if (cnt == input)
				break;
		}
		num++;
	}
	cout << num;
}