#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int *arr, int size, int key) {
	int start = 0;
	int end = size - 1;
	int middle = (start + end) / 2;

	while (start <= end)
	{
		middle = (start + end) / 2;
		if (key == arr[middle])
			return 1;
		else if (key < arr[middle])
			end = middle - 1;
		else
			start = middle + 1;
	}
	return 0;
}

int main() {
	int n;
	scanf_s("%d", &n);
	int *card = new int[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &card[i]);
	}
	sort(card, card + n);
	int m;
	scanf_s("%d", &m);
	int *cmp = new int[m];
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &cmp[i]);
	}
	for (int i = 0; i < m; i++)
	{
		cout <<	binarySearch(card, n, cmp[i])<<' ';
	}
	free(card);
	free(cmp);
	
}

