#include <iostream>
#include <algorithm>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
struct Node {
	int r;
	int c;
	int speed;
	int direction;
	int size;
};
int r, c, m, ans;
Node arr[101][101];
bool isSharkExist(int i, int j);
void removeShark(int i, int j);
void input();
void catchShark(int i, int j) {
	ans += arr[i][j].size;
	removeShark(i, j);
}
queue<Node> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();

	// 1. ���ÿ��� ���������� �� ĭ �̵��Ѵ�.
	rep(pos, c) {
		// 2. ���ÿ��� �ִ� ���� �ִ� ��� �߿��� ���� ���� ����� �� ��´�.�� ������ �����ǿ��� ���� �� �������.
		rep(row, r) {
			if (isSharkExist(row, pos)) {
				catchShark(row, pos);
				break;
			}
		}
		// 3. �� �̵��Ѵ�.
		rep(row, r) {
			rep(col, c) {
				if (isSharkExist(row, col)) {
					Node& now = arr[row][col];
					int nr = row;
					int nc = col;
					int move = now.speed;

					// �� �̵��Ϸ��� �ϴ� ĭ�� �������� ��踦 �Ѵ� ��쿡�� ������ �ݴ�� �ٲ㼭 �ӷ��� ������ä�� �̵��Ѵ�.
					// 1: ��, 2: ��, 3: ��, 4: ��
					if (now.direction == 1) {
						move %= (r - 1) * 2;
						nr = row - move;
						if (nr < 0) {
							now.direction = 2;
							nr *= -1;
							if (nr >= r) {
								now.direction = 1;
								nr = (r - 1) * 2 - nr;
							}

						}
					}
					else if (now.direction == 2) {
						move %= (r - 1) * 2;
						nr = row + move;
						if (nr >= r) {
							now.direction = 1;
							nr = (r - 1) * 2 - nr;
							if (nr < 0) {
								now.direction = 2;
								nr *= -1;
							}
						}
					}
					else if (now.direction == 3) {
						move %= (c - 1) * 2;
						nc = col + move;
						if (nc >= c) {
							now.direction = 4;
							nc = (c - 1) * 2 - nc;
							if (nc < 0) {
								now.direction = 3;
								nc *= -1;
							}
						}
					}
					else if (now.direction == 4) {
						move %= (c - 1) * 2;
						nc = col - move;
						if (nc < 0) {
							now.direction = 3;
							nc *= -1;
							if (nc >= c) {
								now.direction = 4;
								nc = (c - 1) * 2 - nc;
							}

						}
					}

					// �� �̵��� ��ǥ�� ���ϰ� �� ��, ��� �� ��ġ�� �̵���Ű�� (arr[nr][nc])
					// ���� [nr][nc]�� �ִ� �� ����� ��. ����, �ش� ���� �̵����� ����.
					// �̸� �����ϱ� ���ؼ� ����� �� ��ǥ�� ť�� ������ ��, ���߿� �� ���� �̵���Ŵ
					q.push({ nr, nc, now.speed, now.direction, now.size });

					// �̵� �Ϸ�
					removeShark(row, col);
				}
			}
		}
		// ũ�Ⱑ ���� ū �� ������ �� ��� ��ƸԴ´�.
		while (!q.empty()) {
			Node now = q.front(); q.pop();
			arr[now.r][now.c] = (now.size > arr[now.r][now.c].size ? now : arr[now.r][now.c]);
		}
	}
	cout << ans;
}

bool isSharkExist(int i, int j) {
	Node now = arr[i][j];
	if (now.direction != 0 && now.size != 0) return true;
	return false;
}
void removeShark(int i, int j) {
	Node& now = arr[i][j];
	now.r = 0;
	now.c = 0;
	now.size = 0;
	now.direction = 0;
	now.speed = 0;
}
void input() {
	cin >> r >> c >> m;
	rep(i, m) {
		int a, b, s, d, z;
		cin >> a >> b >> s >> d >> z;
		arr[a - 1][b - 1] = { a - 1,b - 1,s,d,z };
	}
}