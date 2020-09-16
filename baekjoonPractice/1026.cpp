#include <iostream>
using namespace std;
void inputArrayData(int arr[], int cnt);
void printArray(int arr[], int cnt);
int getMax(int arr[], int cnt, int &maxIndex);
int getMin(int arr[], int cnt, int &minIndex);
void getRank(int compareArr[], int resultArr[], int cnt);
void initiArray(int arr[], int cnt);
int main() {

	int count = 0;
	int min, max, minIndex, maxIndex = 0;

	cin >> count;
	
	// create array arrA, arrB for input data
	int *arrA = new int[count];
	int *arrB = new int[count];

	// create array rankB, newArrA for calculating
	int *rankB = new int[count];
	int *newArrA = new int[count];

	// input data at arrA, arrB
	inputArrayData(arrA, count);
	inputArrayData(arrB, count);

	// initiate array rankB, newArrA
	initiArray(rankB, count);
	initiArray(newArrA, count);
	getRank(arrB, rankB, count);

	int num = count;

	// rearrangement arrA
	while (num > 0)
	{
		min = getMin(rankB, count, minIndex);
		max = getMax(arrA, count, maxIndex);
		newArrA[minIndex] = max;
		arrA[maxIndex] = -1;
		rankB[minIndex] = 51;

		num--;
		maxIndex = 0;
		minIndex = 0;
	}

	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += newArrA[i] * arrB[i];
	}
	cout << sum;
	delete[] arrA;
	delete[] arrB;
	delete[] rankB;
	delete[] newArrA;
}

void inputArrayData(int arr[], int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i];
	}
}
void printArray(int arr[], int cnt) {
	for (int i = 0; i < cnt; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
int getMax(int arr[], int cnt, int &maxIndex)
{
	int max = arr[0];
	int i = 1;
	for (i = 1; i < cnt; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			maxIndex = i;
		}
	}

	return max;
}
int getMin(int arr[], int cnt, int &minIndex)
{
	int min = arr[0];
	int i = 1;
	for (i = 1; i < cnt; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			minIndex = i;
		}
	}

	return min;
}
void getRank(int compareArr[], int resultArr[], int cnt)
{
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = i + 1; j < cnt; j++) {
			if (compareArr[i] <= compareArr[j])
				resultArr[j]++;
			else
				resultArr[i]++;
		}
	}
}
void initiArray(int arr[], int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		arr[i] = 0;
	}
}