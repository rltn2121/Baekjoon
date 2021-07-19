#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int t,n;
string arr[10001];
bool cmp(const string & a, const string & b, int idx) {
	rep(i, idx) {
		if (a[i] != b[i])
			return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		bool flag = true;
		cin >> n;
		rep(i, n)
			cin >> arr[i];;
		sort(arr, arr + n);

		rep(i, n) {
			if (arr[i].length() >= arr[i + 1].length())
				continue;
			if (!cmp(arr[i], arr[i + 1], arr[i].length())) {
				flag = false;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}

}