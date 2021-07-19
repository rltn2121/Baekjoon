#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define pii pair<int, int>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, l, r, arr[51][51], ans, sum, cnt;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
bool visited[51][51];
queue<pii> q;
vector<pii> v;
bool bfs() {
	bool ret = false;
	rep(i, n) {
		rep(j, n) {
			if (!visited[i][j]) {
				visited[i][j] = 1;
				sum += arr[i][j];
				cnt++;
				v.push_back({ i,j });
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					rep(k, 4) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
						int gap = abs(arr[x][y] - arr[nx][ny]);		
						if (gap >= l && gap <= r) {	// ���̰� L �̻� R �����̸�
							visited[nx][ny] = 1;	// �湮ó��
							q.push({ nx, ny });
							sum += arr[nx][ny];		// �α��� ���ϱ�
							cnt++;					// ���� ���� ���� �߰�
							v.push_back({ nx, ny });// ���� ���� ��ǥ �߰�
						}
					}
				}
				// ���� ������
				if (cnt > 1) {
					ret = true;
					
					int tmp = sum / cnt;
					// ���� ���� �α��� ����
					for (pii p : v) {
						int px = p.first;
						int py = p.second;
						arr[px][py] = tmp;
					}
				}
				sum = 0;
				cnt = 0;
				v.clear();
			}
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> r;
	rep(i, n) {
		rep(j, n)
			cin >> arr[i][j];
	}
	bool flag = true;
	while (flag) {
		memset(visited, 0, sizeof(visited));
		flag = bfs();
		if(flag)
			ans++;
	}
	cout << ans;
}