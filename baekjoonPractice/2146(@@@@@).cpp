#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int groupCnt = 1;
int arr[101][101];
int visited[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
queue<pair<int, int> > q;

void setGroup(int i, int j) {
	q.push({ i, j });
	arr[i][j] = groupCnt;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (arr[nx][ny] != 0 && !visited[nx][ny]) {
					q.push({ nx, ny });
					visited[nx][ny] = true;
					arr[nx][ny] = groupCnt;
				}
			}
		}
	}
}
int getDist(int cnt) {
	queue<pair<int, int> > p;
	for (int i = 0; i < n; i++) {             // 그룹번호가 cnt인 좌표 저장
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == cnt) {
				p.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	int dist = 0;
	while (!p.empty()) {
		int curSize = p.size();
		for (int i = 0; i < curSize; i++) {
			int x = p.front().first;
			int y = p.front().second;
			p.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (arr[nx][ny] != 0 && arr[nx][ny] != cnt)
						return dist;
					if (arr[nx][ny] == 0 && !visited[nx][ny]) {
						p.push({ nx,ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
		dist++;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < n; i++) {                          // 1. 그룹 나누기
		for (int j = 0; j < n; j++) {                      // groupCnt: 그룹 번호
			if (!visited[i][j] && arr[i][j]) {
				setGroup(i, j);
				groupCnt++;
			}
		}
	}

	int result = 999999;
	for (int i = 1; i < groupCnt; i++) {
		memset(visited, false, sizeof(visited));
		result = min(result, getDist(i));
	}
	cout << result << endl;
}
