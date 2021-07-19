#include <iostream>
#include <queue>
#define pii pair<int, int>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m;
char arr[21][21];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
bool visited[20][20][20][20];
queue<pii> q;
void bfs() {
	int cnt = 1;
	while (!q.empty()) {
		int size = q.size() / 2;	// �� ���� �� �� ����
		while (size--){
			if (cnt > 10)			// 10�� �ʰ��ϸ� �Ұ�
				return;
			pii c1 = q.front();
			q.pop();
			pii c2 = q.front();
			q.pop();

			if (c1 == c2)			// �� ������ ��ġ�� �н�
				continue;

			rep(i, 4) {
				int nx1 = c1.first + dx[i];
				int ny1 = c1.second + dy[i];
				int nx2 = c2.first + dx[i];
				int ny2 = c2.second + dy[i];

				bool drop1 = false;
				bool drop2 = false;
				if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= m)
					drop1 = true;
				if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= m)
					drop2 = true;

				if (drop1 && drop2)	// �� �� �������� �н�
					continue;

				else if ((drop1 && !drop2) || (!drop1 && drop2)) {	// �ϳ��� ������
					cout << cnt;
					exit(0);
				}

				if (arr[nx1][ny1] == '#' && arr[nx2][ny2] == '#') continue; // �� �� ���̸� �н�

				if (arr[nx1][ny1] != '#' && arr[nx2][ny2] != '#') {			// �� �� �� �ƴϸ� �̵�
					if (!visited[nx1][ny1][nx2][ny2]) {
						q.push({ nx1, ny1 });
						q.push({ nx2, ny2 });
						visited[nx1][ny1][nx2][ny2] = 1;
					}
				}
				else if(arr[nx1][ny1] == '#' && arr[nx2][ny2] != '#') {		// �� �� �ϳ��� ���̸�
					if (!visited[c1.first][c1.second][nx2][ny2]) {			
						q.push(c1);											// ���̸� ���ڸ� ����
						q.push({ nx2, ny2 });								// �� �ƴϸ� ���� ��ġ ����
						visited[c1.first][c1.second][nx2][ny2] = 1;
					}
				}
				else if (arr[nx1][ny1] != '#' && arr[nx2][ny2] == '#') {
					if (!visited[nx1][ny1][c2.first][c2.second]) {
						q.push({ nx1, ny1 });
						q.push(c2);
						visited[nx1][ny1][c2.first][c2.second] = 1;
					}
				}
					
			}
		}
		cnt++;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') 
				q.push({ i, j });
		}
	}
	if (q.size() == 1) {	// �Էµ� ���� ��ġ�� �ϳ� -> �� ���� ������ ��ħ
		cout << -1;
		exit(0);
	}
	bfs();
	cout << -1;
}