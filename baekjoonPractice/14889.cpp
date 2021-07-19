#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[21][21];
int visited[20];
int min_gap = 987654321;
void dfs(int now, int cnt) {
	if (cnt == n / 2) {
		int score1 = 0;
		int score2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				// ¼±ÅÃµÊ -> ÆÀ1
				if (visited[i] && visited[j])
					score1 += (arr[i][j] + arr[j][i]);
				// ¼±ÅÃ¾ÈµÊ -> ÆÀ2
				else if (!visited[i] && !visited[j])
					score2 += (arr[i][j] + arr[j][i]);
			}
		}
		min_gap = min(min_gap, abs(score1 - score2));
		return;
	}

	// Á¶ÇÕ Ã£±â(n°³ Áß r°³)
	for (int i = now; i < n; i++) {
		visited[i] = true;
		dfs(i + 1, cnt + 1);
		visited[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> arr[i][j];
	}
	
	dfs(0, 0);
	cout << min_gap;
}