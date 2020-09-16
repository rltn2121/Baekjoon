#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int cnt = 0;
	for (char c : str)
		cnt++;
	cout << cnt << endl;
}