#include <iostream>
using namespace std;

void inputEndNumber(int *endNumber, int &ladderCount)
{
	for (int i = 0; i < ladderCount; i++) {
		cin >> endNumber[i];
	}
}
void swap(int &a, int &b)
{
	int temp = b;
	 b = a;
	 a = temp;
}
int sortLadder(int *endNumber, int &ladderCount)
{
	int count = 0;
	for (int i = 0; i < ladderCount-1; i++) 
	{
		for (int j = i + 1; j <= ladderCount-1; j++) 
		{
			if (endNumber[i] > endNumber[j]) 
			{
				swap(endNumber[i], endNumber[j]);
				count++;
			}
		}
	}
	return count;
}
int main() {
	int testCase;
	cin >> testCase;
	while (testCase > 0) {
		int ladderCount;
		cin >> ladderCount;
		int *endNumber = new int[ladderCount];
		
		inputEndNumber(endNumber, ladderCount);
		cout <<sortLadder(endNumber, ladderCount) << endl;

		testCase--;
		free(endNumber);
	}
}