#include <iostream>
#include <algorithm>
#include <vector>
const int INF = 9999999;
using namespace std;
int arr[40000];
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int len = 0;
	v.push_back(-INF);
	for (int i = 0; i < n; i++) {
		if (arr[i] > v.back()) {
			v.push_back(arr[i]);
			len++;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << len << '\n';
}