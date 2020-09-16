#include <iostream>
#include <string>
// stoi(temp) 사용가능
using namespace std;
int intArr[50];
char charArr[50];
int main() {
	int intIdx = 0;
	int charIdx = 0;
	string str;
	cin >> str;
	int temp = 0;
	for (char c : str) {
		if (c == '+' || c == '-') {
			charArr[charIdx++] = c;
			intArr[intIdx++] = temp;
			temp = 0;
		}
		else 
			temp = temp * 10 + (c-'0');
	}
	intArr[intIdx++] = temp;
	bool flag = false;
	int result = intArr[0];
	
	for (int i = 0; i < charIdx; i++) {
		if (charArr[i] == '-')
			flag = true;
		if (flag)
			result -= intArr[i+1];
		else
			result += intArr[i+1];
	}
	cout << result << '\n';
}
