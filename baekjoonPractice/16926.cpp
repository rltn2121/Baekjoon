#include <iostream>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m, r;
int arr[302][302], temp[302][302];
void rotate() {
	int start = 1;
	int n_copy = n;
	int m_copy = m;
	while (start < n_copy && start < m_copy) {
		// 상 하
		for (int i = start; i <= m_copy; i++) {
			arr[start][i] = temp[start][i + 1];
			arr[n_copy][i] = temp[n_copy][i - 1];
		}

		// 좌 우
		for (int i = start; i <= n_copy; i++) {
			if(i > start)
				arr[i][start] = temp[i - 1][start];
			if(i < n_copy)
				arr[i][m_copy] = temp[i + 1][m_copy];
		}
		// 사각형 크기 줄이고 계속
		start++;
		m_copy--;
		n_copy--;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r;
	rep(i, n) {
		rep(j, m) 
			cin >> temp[i][j];
	}
	rep(i, r) {
		rotate();
		rep(i, n) {
			rep(j, m)
				temp[i][j] = arr[i][j];
		}
	}

	rep(i, n) {
		rep(j, m)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}

}