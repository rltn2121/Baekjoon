#include <iostream>
#include <algorithm>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, now = 100, ans = 987654321;
int button[11];
void func(int num, int cnt) {
	// main에서 처음 넘겨주는 num이 0이므로
	// 숫자를 하나도 추가하지 않았을 때(cnt==0)는 검사 안함
	// 처리 안해주면 반례 발생
	if(cnt > 0)
		ans = min(ans, abs(n-num) + cnt);
	
	// 종료 조건
	if (cnt == 6) {
		return;
	}
	// 백트래킹으로 숫자 증가
	for (int i = 0; i < 10; i++) {
		if (button[i]) {
			num = num * 10 + i;
			func(num, cnt +1);
			num = num - i;
			num /= 10;
		}
	}
}
int main() {
	memset(button, 1, sizeof(button));
	cin >> n >> m;
	rep(i, m) {
		int x;
		cin >> x;
		button[x] = 0;
	}
	ans = abs(n - 100);
	
	func(0, 0);
	cout << ans;
}