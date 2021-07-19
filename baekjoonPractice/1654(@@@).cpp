#include <iostream>
#include <algorithm>
#define rep(i,n) for(ll i = 0; i<n; i++)
using namespace std;
typedef long long ll;
int k, n;
ll maxlen;
int cnt = 0;
int has[10000];
int possiblevalue = 0;
int func() {
	ll start = 0;
	ll end = maxlen;
	ll mid = start + (end - start) / 2;
	while (start <= end) {
		mid = start + (end - start) / 2;
		if (start > mid)
			break;
		cnt = 0;
		rep(i, k) 
			cnt += has[i] / mid;
		if (cnt < n)
			end = mid-1;
		else {
			if (mid > possiblevalue)
				possiblevalue = mid;
			start = mid+1;
		}
	}
	return possiblevalue;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> n;
	rep(i, k)
		cin >> has[i];
	sort(has, has + k);
	maxlen = (1<<31)-1;
	cout << func() << endl;
}