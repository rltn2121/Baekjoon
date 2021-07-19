#include <iostream>
#include <algorithm>
#define pii pair<ll, ll>
#define ll long long
#define rep(i,n) for(ll i=1;i<=n;i++)
using namespace std;
ll n;
pii arr[520];
ll m[520][520];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n)
		cin >> arr[i].first >> arr[i].second;
	rep(i, n) {
		rep(j, n) {
			if (i == j) m[i][j] = 0;
			else m[i][j] = (1<<31)-1;
		}
	}

	ll max_diff = n - 1;

	rep(diff, max_diff) {
		rep(i, n - diff) {
			ll j = i + diff;
			for(ll k = i; k<=j-1; k++){
				m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + arr[i].first * arr[k].second * arr[j].second);
			}
			
		}
	}
	cout << m[1][n];
}