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

	// 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
	rep(pos, c) {
		// 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다.상어를 잡으면 격자판에서 잡은 상어가 사라진다.
		rep(row, r) {
			if (isSharkExist(row, pos)) {
				catchShark(row, pos);
				break;
			}
		}
		// 3. 상어가 이동한다.
		rep(row, r) {
			rep(col, c) {
				if (isSharkExist(row, col)) {
					Node& now = arr[row][col];
					int nr = row;
					int nc = col;
					int move = now.speed;

					// 상어가 이동하려고 하는 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.
					// 1: 상, 2: 하, 3: 우, 4: 좌
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

					// 상어가 이동할 좌표를 구하고 난 뒤, 즉시 새 위치로 이동시키면 (arr[nr][nc])
					// 원래 [nr][nc]에 있는 상어를 덮어쓰게 됨. 따라서, 해당 상어는 이동하지 못함.
					// 이를 방지하기 위해서 상어의 새 좌표를 큐에 삽입한 뒤, 나중에 한 번에 이동시킴
					q.push({ nr, nc, now.speed, now.direction, now.size });

					// 이동 완료
					removeShark(row, col);
				}
			}
		}
		// 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.
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