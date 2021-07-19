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
	for (ll i = 1; i <= n; i++) {			// 모든 자리 탐색
		ll cnt = 1;							// 중간에 사용한 것 거르기 위해서 idx, cnt 따로 사용해야 함
		for (ll idx = 1; idx <= n; idx++) {	// 모든 숫자 탐색
			if (used[idx])					// 사용했으면 다음 인덱스 탐색
				continue;

			if (cnt * fact[n - i] >= x) {	// 개수 충분한 지 확인
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
	ll idx = 1;

	while (idx <= n) {
		// 현재 idx의 숫자보다 앞에 있는 숫자의 개수 찾기
		ll cnt = arr[idx] - 1;
		for (ll i = 1; i < arr[idx]; i++) {
			// 앞에 있는 숫자가 이미 사용됐으면 cnt--
			if (used[i])
				cnt--;
		}
		// (내 앞에 올 수 있는 숫자 개수) * (내 뒤에 올 수 있는 경우의 수)
		ans += (cnt * fact[n - idx]);
		used[arr[idx]] = 1;
		idx++;
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