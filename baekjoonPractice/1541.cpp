//#include <iostream>
//#include <string>
//// stoi(temp) 사용가능
//using namespace std;
//int intArr[50];
//char charArr[50];
//int main() {
//	int intIdx = 0;
//	int charIdx = 0;
//	string str;
//	cin >> str;
//	int temp = 0;
//	for (char c : str) {
//		if (c == '+' || c == '-') {
//			charArr[charIdx++] = c;
//			intArr[intIdx++] = temp;
//			temp = 0;
//		}
//		else 
//			temp = temp * 10 + (c-'0');
//	}
//	intArr[intIdx++] = temp;
//	bool flag = false;
//	int result = intArr[0];
//	
//	for (int i = 0; i < charIdx; i++) {
//		if (charArr[i] == '-')
//			flag = true;
//		if (flag)
//			result -= intArr[i+1];
//		else
//			result += intArr[i+1];
//	}
//	cout << result << '\n';
//}

#include <iostream>
#include <string>
using namespace std;
int arr[50];
int main() {
	string str;
	cin >> str;
	int idx = 0;
	int sub_idx=0;
	int temp = 0;
	for (char c : str) {
		if (c >= '0' && c <= '9') {
			temp = temp * 10 + c - '0';
		}
		else {
			arr[idx++] = temp;
			temp = 0;
			if (sub_idx == 0 && c == '-')
				sub_idx = idx;
		}
	}
	arr[idx++] = temp;
	int ans = 0;
	if (sub_idx == 0)
		for (int i = 0; i < idx; i++)
			ans += arr[i];
	else {
		for (int i = 0; i < sub_idx; i++)
			ans += arr[i];

		for (int i = sub_idx; i < idx; i++)
			ans -= arr[i];
	}
	
	cout << ans;
}