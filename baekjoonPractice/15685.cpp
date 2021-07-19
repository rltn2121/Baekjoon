#include <iostream>
#include <stack>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
stack<int> s;
int n, x, y, d, g, arr[101][101];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int idx, direction[1025];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n) {
		idx = 0;
		cin >> y >> x >> d >> g;

		// 1. ���� �ʱ�ȭ
		direction[idx++] = d;
		arr[x][y] = 1;
		rep(j, g) {		// ���� ���� Ž��
			for (int k = idx - 1; k >= 0; k--)
				direction[idx++] = (direction[k] + 1) % 4;
		}

		// 2. ��ǥ ���
		rep(j, idx) {	// ��� �� Ž��
			x += dx[direction[j]];
			y += dy[direction[j]];
			if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
				arr[x][y] = 1;
		}
	}

	// 3. �簢�� �˻�
	int ans = 0;
	rep(x, 100) {
		rep(y, 100) {
			if (arr[x][y] && arr[x][y + 1] && arr[x + 1][y] && arr[x + 1][y + 1])
				ans++;
		}
	}
	cout << ans;
}