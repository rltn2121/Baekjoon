#include <iostream>
#define rep(i, n) for(int i = 0; i<n; i++)
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char b_first[8][8];
	char w_first[8][8];

	// ���� �ʱ�ȭ
	rep(i, 8) {
		rep(j, 8) {
			if ((i + j) % 2 == 0) {
				b_first[i][j] = 'b';
				w_first[i][j] = 'w';
			}
			else {
				b_first[i][j] = 'w';
				w_first[i][j] = 'b';
			}
		}
	}

	char input[50][50];
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		rep(j, m)
			cin >> input[i][j];
	}
	
	int min = 987654321;
	// ���� ��ġ �ٲ㰡�鼭 ���Ϳ� input ��
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int b_cnt = 0;
			int w_cnt = 0;

			for(int k = i; k<i+8; k++){
				for (int l = j; l < j + 8; l++) {
					if (b_first[k - i][l - j] != input[k][l])
						b_cnt++;
					if (w_first[k - i][l - j] != input[k][l])
						w_cnt++;
				}
			}
			// �ּڰ� ã��
			int temp = b_cnt < w_cnt ? b_cnt : w_cnt;
			min = min < temp ? min : temp;
		}
	}
	cout << min;
}