#include <iostream>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, arr[125][125];
int dist[125][125];
struct Node {
	int i, j, weight;
};
struct cmp {
	bool operator()(Node a, Node b) {
		return a.weight > b.weight;
	}
};
void dijkstra() {
	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push({ 0,0,arr[0][0] });
	//dist[0][0] = arr[0][0];
	while (!pq.empty()) {
		int x = pq.top().i;
		int y = pq.top().j;
		int w = pq.top().weight;
		pq.pop();

		rep(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			int nw = w + arr[nx][ny];
			if (dist[nx][ny] > nw) {
				dist[nx][ny] = nw;
				pq.push({ nx, ny, nw });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int cnt = 1;
	while (n != 0) {
		
		rep(i, n) {
			rep(j, n) {
				cin >> arr[i][j];
				dist[i][j] = 1e9;
			}
		}
 
		dijkstra();

		cout << "Problem " << cnt++ << ": " << dist[n - 1][n - 1] << '\n';
		cin >> n;
	}
}