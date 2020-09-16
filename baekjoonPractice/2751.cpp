#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf_s("%d", &t);
	vector<int> arr(t);
	for (int &i : arr) {
		scanf_s("%d", &i);
	}
	sort(arr.begin(), arr.end());
	for (int i : arr) {
		printf("%d\n", i);
	}
}