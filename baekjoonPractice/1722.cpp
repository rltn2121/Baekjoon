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
	for (ll i = 1; i <= n; i++) {			// ��� �ڸ� Ž��
		ll cnt = 1;							// �߰��� ����� �� �Ÿ��� ���ؼ� idx, cnt ���� ����ؾ� ��
		for (ll idx = 1; idx <= n; idx++) {	// ��� ���� Ž��
			if (used[idx])					// ��������� ���� �ε��� Ž��
				continue;

			if (cnt * fact[n - i] >= x) {	// ���� ����� �� Ȯ��
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
		// ���� idx�� ���ں��� �տ� �ִ� ������ ���� ã��
		ll cnt = arr[idx] - 1;
		for (ll i = 1; i < arr[idx]; i++) {
			// �տ� �ִ� ���ڰ� �̹� �������� cnt--
			if (used[i])
				cnt--;
		}
		// (�� �տ� �� �� �ִ� ���� ����) * (�� �ڿ� �� �� �ִ� ����� ��)
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