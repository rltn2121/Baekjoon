#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int max = -1000001;
	int min = 1000001;
	for(int i = 0; i<n; i++) {
		int x;
		cin >> x;
		max = (max > x ? max : x);
		min = (min <x ? min : x);
	}
	cout << min << ' ' << max << endl;
}