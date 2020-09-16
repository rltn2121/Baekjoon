#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++)
		v[i] = i+1;

	int idx = k - 1;
	cout << '<';
	while (v.size() > 1) {
		cout << v[idx] << ", ";
		v.erase(v.begin() + idx);
		if(v.size())
			idx = (idx + k - 1) % v.size();
	}
	cout << v[0] << '>';
}