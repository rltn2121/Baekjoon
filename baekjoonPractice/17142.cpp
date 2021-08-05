#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int, int>
using namespace std;
queue<pii> q;
vector<pii> virus;
int n, m, arr[51][51], copy_arr[51][51], zero_cnt, ans = 1e9;
bool visited[51][51];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
void input();
void bfsInit() {
	memset(visited, 0, sizeof(visited));
	while (!q.empty())
		q.pop();
	zero_cnt = 0;
	rep(i, n) {
		rep(j, n) {
			copy_arr[i][j] = arr[i][j];
			// Ȱ��ȭ�� ���̷����� queue�� �����ϰ� �湮ó��
			if (copy_arr[i][j] == 3) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
			// �� ĭ�� ���� üũ
			else if (copy_arr[i][j] == 0) zero_cnt++;
		}
	}
}
// return �ð�(��)
int bfs() {
	int cnt = 0;
	bfsInit();
	while (!q.empty()) {
		int size = q.size();
		// �� ĭ ������ ����
		if (zero_cnt == 0) break;
		while (size--) {
			pii now = q.front(); q.pop();
			int x = now.first;
			int y = now.second;
			visited[x][y] = 1;
			rep(i, 4) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
				// 1: ���̶� ����
				if (copy_arr[nx][ny] == 1) continue;

				// 0, 2: Ȱ��ȭ ����(3)�� ���� �� ���Ľ�Ŵ
				else if (copy_arr[nx][ny] == 0 || copy_arr[nx][ny]==2) {
					if (copy_arr[nx][ny] == 0) zero_cnt--;
					copy_arr[nx][ny] = 3;
					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
				
				// 3: �̹� visited�� �ɷ��� ��
			}
		}
		cnt++;
	}
	return cnt;
}

void backTrackking(int idx, int cnt) {
	// ���̷����� m�� ��ŭ Ȱ��ȭ �������� bfs ����
	if (cnt == m) {
		int ret = bfs();

		// �� ĭ ������ 0���� ���� ����
		if (zero_cnt == 0)
			ans = min(ans, ret);
		return;
	}

	// ��Ʈ��ŷ���� Ȱ��ȭ��ų ���̷��� ã��
	for (int i = idx; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		if (arr[x][y] == 2) {
			arr[x][y] = 3;
			backTrackking(i, cnt + 1);
			arr[x][y] = 2;
		}
	}
}
// 1. Ȱ��ȭ ��ų ���̷��� �����ϱ� (��Ʈ��ŷ)
// 2. �ð� �󸶳� �ɸ����� ����ϱ� (bfs)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	backTrackking(0, 0);
	cout << (ans==1e9?-1:ans);
}

void input() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				virus.push_back({ i,j });
		}
	}
}