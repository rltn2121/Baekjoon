#include <iostream>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[101][101][2][2];
struct Info {
	int x;
	int y;
	int direction;
};
int w, h;
void bfs(Info info) {
	queue<Info> q;
	q.push(info);
	while (!q.empty()) {
		Info now = q.front();
		q.pop();


	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> w >> h;
	// i, j, 0, 0	: 오른쪽, 안꺾음
	// i, j, 0, 1	: 오른쪽, 꺾음
	// i, j, 1, 0	: 아래, 안꺾음
	// i, j, 1, 1	: 아래, 꺾음

	// 첫 행 오른쪽 이동
	rep(i, w) {
		arr[0][i][0][0] = 1;
	}

	// 첫 열 아래쪽 이동
	rep(i, h) {
		arr[i][0][1][0] = 1;
	}


}