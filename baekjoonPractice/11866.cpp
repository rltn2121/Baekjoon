#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++)
		v.push_back(i + 1);

	int idx = 0;
	cout << '<';
	while (!v.empty()) {
		idx = (idx + (k-1)) % n;
		cout << v[idx];
		v.erase(v.begin() + idx);
		n--;
		if (!v.empty())
			cout << ", ";
	}
	cout << '>';
}