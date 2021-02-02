#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll arr[21], used[21];
ll n, m;
ll fact[21];

void init_fact() {
	fact[0] = 1;
	for (ll i = 1; i <= n; i++) {
		fact[i] = i * fact[i - 1];
	}
}
void func1() {
	ll x;
	cin >> x;
	for (ll i = 1; i <= n; i++) {
		// 중간에 사용한 것 거르기 위해서 idx, cnt 따로 사용해야 함
		ll cnt = 1;

		for (ll idx = 1; idx <= n; idx++) {
			// 사용했으면 다음 인덱스 탐색
			if (used[idx])
				continue;

			if (cnt * fact[n - i] >= x) {
				cout << idx << ' ';
				used[idx] = true;
				x -= (cnt - 1) * fact[n - i];
				break;
			}
			cnt++;
		}
	}
}
void func2() {
	for (ll i = 1; i <= n; i++)
		cin >> arr[i];

	ll ans = 1;
	ll cnt = 1;

	while (cnt <= n) {
		ll val = arr[cnt] - 1;
		for (ll i = 1; i < arr[cnt]; i++) {
			if (used[i])
				val--;
		}
		ans += (val * fact[n - cnt]);
		used[arr[cnt]] = 1;
		cnt++;
	}
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	init_fact();

	if (m == 1)
		func1();
	else 
		func2();
}