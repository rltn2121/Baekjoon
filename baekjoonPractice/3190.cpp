#include <iostream>
#include <queue>
#define pii pair<int, int>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int arr[101][101], n, k, a, b, l, x;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
char c, turn[10001];
bool visited[101][101];
queue<pii> q;
void dfs(int x, int y, int direction, int sec) {
	// 종료 조건
	// 1. 벽에 부딪힘
	// 2. 자기 몸에 부딪힘
	if (x <= 0 || x > n || y <= 0 || y > n || visited[x][y]) {
		cout << sec;
		exit(0);
	}

	// 머리 방문
	visited[x][y] = 1;
	q.push({ x, y });

	// 사과 없으면 꼬리 줄이기
	if (!arr[x][y]) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		visited[tx][ty] = 0;
	}

	// 사과 한 번 먹으면 더 이상 못 먹음
	arr[x][y] = 0;	

	// 방향 전환
	int next_direction = direction;
	if (turn[sec] == 'L') 
		next_direction = (direction + 3) % 4;
	else if(turn[sec] == 'D')
		next_direction = (direction + 1) % 4;

	// 머리 다음 위치
	int nx = x + dx[next_direction];
	int ny = y + dy[next_direction];
	dfs(nx, ny, next_direction, sec + 1);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	rep(i, k) {
		cin >> a >> b;
		arr[a][b] = 1;
	}
	cin >> l;
	rep(i, l) {
		cin >> x >> c;
		turn[x] = c;
	}
	q.push({ 1,1 });
	visited[1][1] = 1;
	dfs(1, 2, 0, 1);
}