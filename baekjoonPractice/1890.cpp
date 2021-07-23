#include <iostream>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;
struct Node {
	int x;
	int y;
};
struct cmp {
	bool operator()(Node a, Node b) {
		return a.x + a.y > b.x + b.y;
	}
};
int n, arr[101][101];
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
bool visited[101][101];
ll dp[101][101];
void func() {
	priority_queue<Node, vector<Node>, cmp> q;
	q.push({ 0,0 });
	dp[0][0] = 1;
	visited[0][0] = 1;
	while (!q.empty()) {
		Node now = q.top(); q.pop();
		int x = now.x;
		int y = now.y;
		if (arr[x][y] == 0) continue;
		rep(i, 2) {
			int nx = x + dx[i] * arr[x][y];
			int ny = y + dy[i] * arr[x][y];
			if (nx >= n || ny >= n) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
			dp[nx][ny] += dp[x][y];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		rep(j, n)
			cin >> arr[i][j];
	}
	func();
	cout << dp[n - 1][n - 1];
}