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
	// i, j, 0, 0	: ������, �Ȳ���
	// i, j, 0, 1	: ������, ����
	// i, j, 1, 0	: �Ʒ�, �Ȳ���
	// i, j, 1, 1	: �Ʒ�, ����

	// ù �� ������ �̵�
	rep(i, w) {
		arr[0][i][0][0] = 1;
	}

	// ù �� �Ʒ��� �̵�
	rep(i, h) {
		arr[i][0][1][0] = 1;
	}


}