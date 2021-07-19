#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, arr[12], op[50];
int max_val = -987654321, min_val = 987654321;
// ������ ��� ����: +(1) +(2) + (3) / +(2) +(1) +(3) / +(1) +(3) +(2) ��� �ٸ� ���� �ν�
// ������ �����ִ� ������ Ȯ���ؼ� Ž���ϴ� ������� �ؾ���
void func(int step, int val) {
	if (step == n) {
		max_val = max(max_val, val);
		min_val = min(min_val, val);
		return;
	}
	rep (i, 4) {
		if (op[i]>0) {		// ���� ������ ����������
			op[i]--;		// �ϳ� ���
			int temp = 0;
			if (i == 0)
				temp = val + arr[step];
			else if (i == 1)
				temp = val - arr[step];
			else if (i == 2)
				temp = val * arr[step];
			else if (i == 3)
				temp = val / arr[step];
			func(step + 1, temp);	// ���� ���� ���
			op[i]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n)
		cin >> arr[i];

	rep(i, 4)
		cin >> op[i];
	func(1, arr[0]);
	cout << max_val << '\n' << min_val;
}