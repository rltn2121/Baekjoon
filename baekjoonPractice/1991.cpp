#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n;
int arr[26][2];
void pre(int i) {
	if (i == -1) return;
	
	cout << (char)(i + 'A');
	pre(arr[i][0]);
	pre(arr[i][1]);
}
void in(int i) {
	if (i == -1) return;

	in(arr[i][0]);
	cout << (char)(i + 'A');
	in(arr[i][1]);
}
void post(int i) {
	if (i == -1) return;

	post(arr[i][0]);
	post(arr[i][1]);
	cout << (char)(i + 'A');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		char parent, left, right;
		cin >> parent >> left >> right;
		if (left == '.')
			arr[parent - 'A'][0] = -1;
		else
			arr[parent - 'A'][0] = left - 'A';

		if (right == '.')
			arr[parent - 'A'][1] = -1;
		else
			arr[parent - 'A'][1] = right - 'A';
	}

	pre(0); cout << '\n';
	in(0);  cout << '\n';
	post(0); cout << '\n';
}