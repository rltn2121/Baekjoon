#include <iostream>
#include <string>
using namespace std;
typedef struct Birth {
	string name;
	int day;
	int month;
	int year;
}Birth;

static int peopleCount = 0;

string getOldestPerson(Birth *b) {
	int maxIndex = 0;
	for (int i = 0; i < peopleCount; i++) {
		if (b[maxIndex].year <b[i].year)
			maxIndex = i;
		else if (b[maxIndex].year == b[i].year)
		{
			if (b[maxIndex].month < b[i].month)
				maxIndex = i;
			else if (b[maxIndex].month == b[i].month)
			{
				if (b[maxIndex].day < b[i].day)
					maxIndex = i;
			}
		}
	}
	return b[maxIndex].name;
}

string getYoungestPerson(Birth *b) {
	int minIndex = 0;
	for (int i = 0; i < peopleCount; i++) {
		if (b[minIndex].year >b[i].year)
			minIndex = i;
		else if (b[minIndex].year == b[i].year)
		{
			if (b[minIndex].month > b[i].month)
				minIndex = i;
			else if (b[minIndex].month == b[i].month)
			{
				if (b[minIndex].day > b[i].day)
					minIndex = i;
			}
		}
	}
	return b[minIndex].name;
}
int main() {
	int person;
	cin >> person;

	Birth *arr = new Birth[person];

	for (int i = 0; i < person; i++) {
		cin >> arr[i].name >> arr[i].day >> arr[i].month >> arr[i].year;
		peopleCount++;
	}
	string oldest = getOldestPerson(arr);
	string youngest = getYoungestPerson(arr);
	cout << oldest << '\n' << youngest;


	
	
}