//#include <iostream>
//#include <queue>
//#define rep(i,n) for(int i=0;i<n;i++)
//#define INF 1e9
//using namespace std;
//int n, arr[2223][2223];
//int cost[2223][2223];
//int dx[] = { 0, 1 };
//int dy[] = { 1, 0 };
//struct Node {
//	int x;
//	int y;
//	int cnt;
//};
//void dijk() {
//	queue<Node> pq;
//	pq.push({ 0,0,0 });
//	cost[0][0] = 0;
//	while (!pq.empty()) {
//		Node now = pq.front(); pq.pop();
//		int x = now.x;
//		int y = now.y;
//		if (now.cnt > cost[x][y]) continue;
//		rep(i, 2) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx >= n || ny >= n) continue;
//
//			int cnt = 0;
//			while (arr[x][y]+cnt <= arr[nx][ny])	// 다음 위치로 이동할 수 있을때 까지 버튼 누름
//				cnt++;
//
//			// 현재 버튼 누른 횟수와 비교
//			if (now.cnt + cnt < cost[nx][ny]) {
//				cost[nx][ny] = now.cnt+cnt;
//				pq.push({ nx, ny, now.cnt+cnt });
//			}
// 		}
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> n;
//	rep(i, n) {
//		rep(j, n) {
//			cin >> arr[i][j];
//			cost[i][j] = INF;
//		}
//	}
//
//	dijk();
//	cout << cost[n-1][n-1];
//}