/*
	1. sort(), binary_search() 사용
	2. set->count() 사용
	※ map, set에서 [], find 쓰면 시간초과
*/

#define rep(i,n) for(int i=0;i<n;i++)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
bool find(int start, int end, int x) {
	int mid = (start + end) / 2;
	while (start <= end) {
		if (v[mid] == x)
			return true;
		else if (x < v[mid])
			return find(start, mid - 1, x);
		else
			return find(mid + 1, end, x);
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		v.clear();
		int n;
		cin >> n;
		v.reserve(n);
		rep(i, n) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int m;
		cin >> m;
		rep(i, m) {
			int x;
			cin >> x;

			cout << (find(0, v.size() - 1, x) ? 1 : 0) << '\n';
		}
	}
}