//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define rep(i,n) for(int i = 0; i<n; i++)
//using namespace std;
//int n,m,a;
//vector<int> v;
//bool bs(int x) {
//	int left = 0;
//	int right = n - 1;
//	int mid = (left + right) / 2;
//
//	while (left <= right) {
//		mid = (left + right) / 2;
//		if (v[mid] == x)
//			return true;
//		else if (v[mid] > x)
//			right = mid - 1;
//		else
//			left = mid + 1;
//	}
//	return false;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> n;
//	rep(i, n) {
//		cin >> a;
//		v.push_back(a);
//	}
//	sort(v.begin(), v.begin() + n);
//	cin >> m;
//	while (m--) {
//		cin >> a;
//		cout << bs(a) << ' ';
//	}
//}

#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
bool positive[10000001];
bool negative[10000001];
//vector<bool> v;
bool result[10000001];
int main() { 
	int n, m, a;
	cin >> n;
	rep(i,n) { 
		cin >> a;
		if (a >= 0) 
			positive[a] = 1;
		else 
			negative[-a] = 1;
	}

	cin >> m;
	//v.reserve(m);
	int idx = 0;
	rep(i,m) {
		cin >> a;
		if (a >= 0)
			//v.push_back(positive[a]);
			result[idx++] = positive[a];
		else
			result[idx++] = negative[-a];
			//v.push_back(negative[-a]);
	}
	rep(i, m)
		//cout << v[i] << " ";
		cout << result[i] << ' ';
}