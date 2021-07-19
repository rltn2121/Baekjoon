#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int origin[1001];
bool visited[1001];
bool cmp(int a, int b) {
	return a < b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(null);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		origin[i] = arr[i];
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j] == origin[i] && !visited[j]) {
				cout << j << ' ';
				visited[j] = 1;
				break;
			}
		}
	}
}