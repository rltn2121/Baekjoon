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
	// 배열 왼쪽
	while (mask < (1 << len)) {
		tmp = 0;
		rep(i, len) 
			tmp += ((mask >> i) & 1)* arr[i];
		
		a1[tmp + 2000000]++;
		mask++;
	}

	// 배열 오른쪽
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

	// 1. 배열 나눠서 부분수열 계산
	calc();
	
	// 2. 투 포인터로 탐색
	ll p1 = 0, p2 = 4000000;
	if (s == 0)
		ans--;
	s += 4000000;
	while (1) {
		while (p1 + p2 > s)		// s보다 크면 p2를 이동시켜서 더 작게 만들기
			p2--;
		while (p1 + p2 < s)		// s보다 작으면 p1을 이동시켜서 더 크게 만들기
			p1++;
		if (p1 > 4000000 || p2 < 0) break;	// 범위 벗어나면 종료
		if (p1 + p2 == s)		// s와 같으면 더하기
			ans += a1[p1] * a2[p2];
		p1++;					// 다음 탐색 진행을 위해 p1 오른쪽으로 이동
	}
	cout << ans;
}