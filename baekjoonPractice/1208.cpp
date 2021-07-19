#include <iostream>
#define rep(i,n) for(ll i=0;i<n;i++)
#define ll long long
using namespace std;
ll arr[41], a1[4000001], a2[4000001];
ll n, s, ans;

void calc() {
	ll mask = 0;
	ll tmp = 0;
	ll len = n / 2;
	// �迭 ����
	while (mask < (1 << len)) {
		tmp = 0;
		rep(i, len) 
			tmp += ((mask >> i) & 1)* arr[i];
		
		a1[tmp + 2000000]++;
		mask++;
	}

	// �迭 ������
	mask = 0;
	if (n % 2 == 1)
		len++;
	
	while (mask < (1 << len)) {
		tmp = 0;
		rep(i, len)
			tmp += ((mask >> i) & 1)* arr[i + n / 2];
		
		a2[tmp + 2000000]++;
		mask++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	rep(i, n)
		cin >> arr[i];

	// 1. �迭 ������ �κм��� ���
	calc();
	
	// 2. �� �����ͷ� Ž��
	ll p1 = 0, p2 = 4000000;
	if (s == 0)
		ans--;
	s += 4000000;
	while (1) {
		while (p1 + p2 > s)		// s���� ũ�� p2�� �̵����Ѽ� �� �۰� �����
			p2--;
		while (p1 + p2 < s)		// s���� ������ p1�� �̵����Ѽ� �� ũ�� �����
			p1++;
		if (p1 > 4000000 || p2 < 0) break;	// ���� ����� ����
		if (p1 + p2 == s)		// s�� ������ ���ϱ�
			ans += a1[p1] * a2[p2];
		p1++;					// ���� Ž�� ������ ���� p1 ���������� �̵�
	}
	cout << ans;
}