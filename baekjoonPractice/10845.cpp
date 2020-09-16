#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
	int count = 0;
	queue<int> intQueue;
	cin >> count;

	while (count > 0)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int num;
			cin >> num;
			intQueue.push(num);
		}
		else if (cmd == "pop")
		{ 
			if (intQueue.empty())
				cout << -1 << endl;
			else
			{
				cout << intQueue.front() << endl;
				intQueue.pop();
			}
		}
		else if (cmd == "size")
			cout << intQueue.size() << endl;
		else if (cmd == "empty")
			cout << intQueue.empty() << endl;
		else if (cmd == "front")
		{
			if (intQueue.empty())
				cout << -1 << endl;
			else
				cout << intQueue.front() << endl;
		}
		else if (cmd == "back")
		{
			if (intQueue.empty())
				cout << -1 << endl;
			else
				cout << intQueue.back() << endl;
		}
		count--;
	}
}