#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int x, arr[1000001];
int n1, n2, n3, ans;
int main() {
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	cin >> x;
	for (int i = 4; i <= x;i++) {
		n1 = n2 = n3 = 987654321;
		
		if (i % 3 == 0)
			n3 = arr[i / 3];
		if (i % 2 == 0)
			n2 = arr[i / 2];
		n1 = arr[i - 1];
		arr[i] = 1+min(n1, min(n2, n3));
	}
	cout << arr[x];
}