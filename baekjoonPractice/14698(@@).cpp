#include <iostream>
#include <queue>
#include <stack>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define div 1000000007
using namespace std;
stack<ll> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {

		priority_queue<ll, vector<ll>, greater<ll> > pq;
		cin >> n;
		rep(i, n) {
			ll x;
			cin >> x;
			pq.push(x);
		}

		while (pq.size() >= 2) {
			ll a = pq.top() % div;
			pq.pop();
			ll b = pq.top() % div;
			pq.pop();
			pq.push(a * b);
			s.push(a * b);
		}

		ll ans = 1;
		while (!s.empty()) {
			ans = (ans % div) * (s.top() % div);
			s.pop();
		}
		cout << ans % div << '\n';
	}
}