#include <iostream>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int, int>
using namespace std;
char arr[51][51];
int r, c;
/*
	.: ºó Ä­
	*: ¹°
	X: µ¹
	D: ºñ¹öÀÇ ±¼
	S: °í½¿µµÄ¡ÀÇ À§Ä¡
*/

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
queue<pii> water;
queue<pii> gosum;
bool visited_water[51][51];
bool visited_gosum[51][51];
int cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	rep(i, r) {
		rep(j, c) {
			char x;
			cin >> x;
			arr[i][j] = x;
			if (x == 'S') // °í½¿µµÄ¡
				gosum.push({ i,j });
			else if (x == '*') // ¹°
				water.push({ i,j });
		}
	}

	
	while (!gosum.empty()) {
		cnt++;

		// ¹° ÀÌµ¿
		int q_size = water.size();
		while (q_size--) {
			pii now = water.front();
			water.pop();
			int x = now.first;
			int y = now.second;
			visited_water[x][y] = 1;
			rep(i, 4) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == 'X' || arr[nx][ny] == 'D' || visited_water[nx][ny]) continue;
				visited_water[nx][ny] = 1;
				water.push({ nx, ny });
			}
		}

		// °í½¿µµÄ¡ ÀÌµ¿
		q_size = gosum.size();
		while (q_size--) {
			pii now = gosum.front();
			gosum.pop();
			int x = now.first;
			int y = now.second;
			visited_gosum[x][y] = 1;
			rep(i, 4) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == 'X' || visited_water[nx][ny] || visited_gosum[nx][ny]) continue;
				if (arr[nx][ny] == 'D') {
					cout << cnt;
					return 0;
				}
				visited_gosum[nx][ny] = 1;
				gosum.push({ nx, ny });
			}
		}
		
	}
	cout << "KAKTUS";
}