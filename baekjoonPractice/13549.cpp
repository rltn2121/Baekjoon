#include <iostream>
#include <queue>
using namespace std;
int n, k, cnt;
bool visited[200001];
queue<int> q;
bool valid(int x) {
	if (x >= 0 && x <= 100000)
		return true;
	return false;
}
void insert(int x) {
	if (!valid(x)) return;
	if (!visited[x]) {
		q.push(x);
		visited[x] = 1;
	}
}

void teleport(int n) {			// 순간이동 할 수 있는 위치 (n*2) 모두 삽입
	if (!valid(n)) return;
	for (int i = n; i <= 100000; i *= 2) {
		if (!visited[i]) {
			q.push(i);
			visited[i] = 1;
		}
		if (i == 0) break;		// 0일 때 순간이동 못함 -> 무한루프
	}
}
void bfs(int n) {
	teleport(n);
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int now = q.front();
			q.pop();
			if (now == k) {
				cout << cnt;
				return;
			}
			insert(now - 1);	// 앞으로 이동
			insert(now + 1);	// 뒤로 이동

			teleport(now - 1);	// 앞에서 순간이동 할 수 있는 위치 모두 삽입
			teleport(now + 1);	// 뒤에서 순간이동 할 수 있는 위치 모두 삽입
		}
		cnt++;
	}
}
int main() {
	cin >> n >> k;
	bfs(n);
}