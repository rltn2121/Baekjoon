#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// 10만보다 더 큰 곳으로 가서 -1 해서 갈 수도 있음
int n, k, now, visited[200001], parent[200001];
queue<int> q;
stack<int> s;
bool valid(int n) {
	if (!visited[n] && n >= 0 && n <= 100000)
		return true;
	return false;
}
void insert(int n) {
	if (valid(n)) {
		parent[n] = now;
		visited[n] = 1;
		q.push(n);
	}
}
void print() {
	while (now != -1) {
		s.push(now);		// 역순으로 출력하기 위해 stack 사용
		now = parent[now];	// 부모 따라서 계속 감
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}

void bfs(int start, int cnt) {
	parent[start] = -1;
	visited[start] = 1;
	q.push(start);
	while (!q.empty()) {
		cnt++;
		// 단계별로 진행
		int size = q.size();
		while (size--) {
			now = q.front();
			q.pop();
			
			if (now == k) {				// 동생 찾았으면 출력
				cout << cnt << '\n';
				print();
				exit(0);
			}

			insert(now - 1);			// Queue에 넣을 때 부모 정보 입력
			insert(now + 1);
			insert(now * 2);
		}
	}
}
int main() {
	cin >> n >> k;
	
	bfs(n, -1);
}