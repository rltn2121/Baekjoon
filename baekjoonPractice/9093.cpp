#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main() {
	
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string str;
		stack<char> s;
		
		getline(cin, str);
		// 정답
		str.append(" ");
		for (int i = 0; i <= str.length(); i++) {
			if (str[i] == ' ') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				i++;
				cout << ' ';
			}
			s.push(str[i]);
		}
		cout << endl;

		// 오답
		/*int idx = 0;
		vector<string> arr;
		arr.resize(1000);
		for (int i = 0; i < str.length()-1; i++) {
			while (str[i] != ' ')			{
				if (i == str.length())
					break;
				arr[idx].push_back(str[i++]);
			}
			idx++;
		}

		int i = 0;
		while (arr[i] != "")
		{
			for (int j = arr[i].length() - 1; j >= 0; j--)
				cout << arr[i][j];
			cout << ' ';
			i++;
		}
		cout << '\n';
	}*/
	}
}