#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isVPS(string& PS)
{
	stack<int> psStack;
	
	for (int i = 0; i <PS.length(); i++)
	{
		if (PS[i] == '(')
		{
			psStack.push(1);
		}
		else if (PS[i] == ')')
		{
			if (psStack.empty())
				return false;
			psStack.pop();
		}
	}
	if (psStack.empty())
		return true;
	else
		return false;
}
int main() {
	int testCase = 0;
	cin >> testCase;
	while (testCase > 0) {
		string psString;
		cin >> psString;
		if (isVPS(psString))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
		testCase--;
	}
}