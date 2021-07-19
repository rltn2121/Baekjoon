//#include <iostream>
//#include <queue>
//using namespace std;
//int n, k, ans, step = 0;
//queue<int> q;
//bool visited[100001];
//
//void insert(int n) {
//	if ((n - 1) >= 0 && !visited[n - 1]) {
//		visited[n - 1] = 1;
//		q.push(n - 1);
//	}
//	if ((n + 1) <= 100000 && !visited[n + 1]) {
//		visited[n + 1] = 1;
//		q.push(n + 1);
//	}
//	if ((2 * n <= 100000) && !visited[2 * n]) {
//		visited[2 * n] = 1;
//		q.push(2 * n);
//	}
//}
//void bfs(int n) {
//	q.push(n);
//	visited[n] = 1;
//	while (!q.empty()) {
//		int size = q.size();
//		while (size--) {
//			int now = q.front();
//			q.pop();
//			if (now == k)
//				return;
//			insert(now);
//		}
//		ans++;
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> n >> k;
//	bfs(n);
//	cout << ans;
//}