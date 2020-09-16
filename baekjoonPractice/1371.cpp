#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	int arr[26] = { 0, };
	while (getline(cin, str)) {
		for (char c : str){
			int a = c;
			if (c < 97)
				continue;
			arr[a-97]++;
		}
	}
	
	int max = arr[0];
	for (int i = 1; i < 26; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	
	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) {
			char c = i + 97;
			cout << c;
		}
	}
}