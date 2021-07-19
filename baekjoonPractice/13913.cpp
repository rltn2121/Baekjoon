#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// 10������ �� ū ������ ���� -1 �ؼ� �� ���� ����
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
		s.push(now);		// �������� ����ϱ� ���� stack ���
		now = parent[now];	// �θ� ���� ��� ��
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
		// �ܰ躰�� ����
		int size = q.size();
		while (size--) {
			now = q.front();
			q.pop();
			
			if (now == k) {				// ���� ã������ ���
				cout << cnt << '\n';
				print();
				exit(0);
			}

			insert(now - 1);			// Queue�� ���� �� �θ� ���� �Է�
			insert(now + 1);
			insert(now * 2);
		}
	}
}
int main() {
	cin >> n >> k;
	
	bfs(n, -1);
}