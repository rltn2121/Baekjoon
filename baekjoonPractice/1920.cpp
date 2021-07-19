#include <iostream>
#include <algorithm>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	rep(i, n) {
		cin >> arr[i];
	}
	sort(arr, arr+n);

	cin >> m;
	rep(i, m) {
		ll x;
		cin >> x;
		int start = 0;
		int end = n;
		bool flag = 0;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (arr[mid] == x) {
				flag = 1;
				break;
			}
			else if (arr[mid] > x) {
				end = mid - 1;
			}
			else if (arr[mid] < x) {
				start = mid + 1;
			}
		}
		cout << flag << '\n';
	}
}