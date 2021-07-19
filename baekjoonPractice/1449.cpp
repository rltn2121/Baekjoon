#include <iostream>
#include <algorithm>
using namespace std;
int n, l;
int arr[1001];
double tape[1001];
int main() {
	cin >> n >> l;
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int tape_idx = 0;
	tape[0] = (double)(arr[0] - 0.5);
	for (int i = 1;i < n;i++) {
		if (arr[i] >= tape[tape_idx] + l) 
			tape[++tape_idx] = arr[i] - 0.5;
		
	}
	cout << tape_idx + 1;
}