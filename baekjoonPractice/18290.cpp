#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k, arr[11][11];
int visited[11][11];
// ��� ���ڰ� ������ ���� �����Ƿ� -987654321���� �ʱ�ȭ
int ans = -987654321, temp = 0;
vector<pair<int, int> > v;
void visit(int i, int j, int state) {
	if (state == 1) {
		// ��ġ�� ������ �� �� �̻��� ���� �����Ƿ� visited[][]=1�� �ƴ� visited[][]++
		visited[i][j]++;
		if (i - 1 >= 0) visited[i - 1][j]++;
		if (j - 1 >= 0) visited[i][j - 1]++;
		if (i + 1 < n) visited[i + 1][j]++;
		if (j + 1 < m) visited[i][j + 1]++;
	}
	else {
		visited[i][j]--;
		if (i - 1 >= 0) visited[i - 1][j]--;
		if (j - 1 >= 0) visited[i][j - 1]--;
		if (i + 1 < n) visited[i + 1][j]--;
		if (j + 1 < m) visited[i][j + 1]--;
	}
}
void dfs(int x, int y, int cnt) {
	if (cnt == k) {
		ans = max(ans, temp);
		return;
	}
	for (int i = x; i < n;i++) {
		y = 0;
		for (int j = y; j < m;j++) {
			if (visited[i][j]==0) {
				visit(i, j, 1);
				temp += arr[i][j];
				v.push_back({ i,j });
				dfs(i, j, cnt + 1);
				v.erase(v.end() - 1);
				temp -= arr[i][j];
				visit(i, j, 0);
			}
		}
		
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			cin >> arr[i][j];
	}
	dfs(0, 0, 0);
	cout << ans;
}