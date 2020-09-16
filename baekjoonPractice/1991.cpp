#include <iostream>
#include <map>
using namespace std;
int arr[100][2];
map <char, pair<char, char> > m;
void preorder(int n) {
	if (n == -1) return;
	cout << (char)(n+'A');
	preorder(arr[n][0]);
	preorder(arr[n][1]);
}

void inorder(int n) {
	if (n == -1) return;
	
	inorder(arr[n][0]);
	cout << (char)(n + 'A');	
	inorder(arr[n][1]);
}

void postorder(int n) {
	if (n == -1) return;

	postorder(arr[n][0]);
	
	postorder(arr[n][1]);
	cout << (char)(n + 'A');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	char parent, left, right;
	for (int i = 0; i < n; i++) {
		cin >> parent >> left >> right;
		if (left == '.')
			arr[parent - 'A'][0] = -1;
		else
			arr[parent - 'A'][0] = left-'A';
		if (right == '.')
			arr[parent - 'A'][1] = -1;
		else
			arr[parent - 'A'][1] = right - 'A';
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
}