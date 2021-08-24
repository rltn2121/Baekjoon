#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int, int>
using namespace std;
pii p_pos;
char arr[50][50];
int height[50][50], n, k_cnt, ans;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<int> height_list;

// low ~ high 사이에 있는 칸만 가기
int bfs(int low, int high) {
	int ret = 0;
	bool visited[50][50] = { 0, };

	queue<pii> q;
	int start_height = height[p_pos.first][p_pos.second];
	if (start_height < low || start_height > high) return -1;
	q.push(p_pos);
	visited[p_pos.first][p_pos.second] = 1;

	while (!q.empty() && ret < k_cnt) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		rep(i, 8) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
			if (height[nx][ny] < low || height[nx][ny] > high) continue;
			visited[nx][ny] = 1;
			q.push({ nx, ny });
			if (arr[nx][ny] == 'K') ret++;
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	rep(i, n) {
		rep(j, n) {
			cin >> arr[i][j];
			if (arr[i][j] == 'K') k_cnt++;
			if (arr[i][j] == 'P') p_pos = { i, j };
		}
	}

	rep(i, n) {
		rep(j, n) {
			cin >> height[i][j];
			height_list.push_back(height[i][j]);
		}
	}
	sort(height_list.begin(), height_list.end());

	int low_idx = 0, high_idx = 0;

	int ans = height_list.back() - height_list[0];

	while (low_idx <= high_idx && high_idx < n*n) {
		int low = height_list[low_idx];
		int high = height_list[high_idx];
		int cnt = bfs(low, high);

		if (cnt == k_cnt) {
			ans = min(ans, high - low);
			low_idx++;
		}
		else
			high_idx++;
	}
	cout << ans;
}