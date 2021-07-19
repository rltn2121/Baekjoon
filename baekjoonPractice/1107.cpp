#include <iostream>
#include <algorithm>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, now = 100, ans = 987654321;
int button[11];
void func(int num, int cnt) {
	// main���� ó�� �Ѱ��ִ� num�� 0�̹Ƿ�
	// ���ڸ� �ϳ��� �߰����� �ʾ��� ��(cnt==0)�� �˻� ����
	// ó�� �����ָ� �ݷ� �߻�
	if(cnt > 0)
		ans = min(ans, abs(n-num) + cnt);
	
	// ���� ����
	if (cnt == 6) {
		return;
	}
	// ��Ʈ��ŷ���� ���� ����
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