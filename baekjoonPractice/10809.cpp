#include <iostream>
#include <string>
int main() {
	std::string str;
	std::cin >> str;
	int count[26];
	for (int i = 0; i < 26; i++)
		count[i] = -1;
	std::cout << std::endl;
	for (size_t i = 0; i < str.length(); i++) {
		int c = str[i];
		if (count[c - 97] != -1)
			continue;
		count[c - 97] = i;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", count[i]);
}