#include <iostream>
#include <string>	
using namespace std;
int main() {

	string str;
	getline(cin, str);
	char space = ' '; // str[i] == '\0' æ»≈Î«‘
	int wordCount = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == space)
			wordCount++;
	}
	int len = str.length();
	if (str[0] == space)
		wordCount--;
	if (str[len - 1] == space)
		 wordCount--;
	cout <<wordCount+1 << endl;
}