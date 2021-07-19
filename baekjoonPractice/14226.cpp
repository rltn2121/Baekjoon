// https://yabmoons.tistory.com/74
#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;
int n, cnt;
bool visited[1001][1001];
queue<pii> q;
void bfs(int i, int j) {
	visited[i][j] = 1;
	q.push({ i,j });
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {
			int screen = q.front().first;
			int clipboard = q.front().second;
			q.pop();
			if (screen == n) {		// 화면 이모티콘 n개 되면 종료
				cout << cnt;
				return;
			}
			// 1. 복사
			if (!visited[screen][screen]) {
				visited[screen][screen] =1;
				q.push({ screen, screen });
			}
			// 2. 붙여넣기
			if (screen + clipboard <= 1000 && !visited[screen + clipboard][clipboard]) {
				visited[screen + clipboard][clipboard] =1;
				q.push({ screen + clipboard, clipboard });
			}
			// 3. 삭제
			if (screen > 0 && !visited[screen - 1][clipboard]) {
				visited[screen - 1][clipboard] = 1;
				q.push({ screen - 1, clipboard });
			}
		}
	}
}
int main() {
	cin >> n;
	bfs(1, 1);
}