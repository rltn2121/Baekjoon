#include <iostream>
#include <queue>
#include <cstring>
#define pii pair<int, int>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, k, sum[1001][1001], ans, max_val, cnt;
pii temp;
queue<pii> q;
void init();
void input();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(t, n) {
		init();
		input();
		rep(i, k) {
			for (int j = i; j <= k; j++) {
				if(i!=j)
					sum[i][j] += sum[i][j - 1] + sum[j][j];
				// 누적합이 더 크면
				if (sum[i][j] > max_val) {
					max_val = sum[i][j];
					temp.first = i;
					temp.second = j;
					cnt = j - i + 1;
				}

				// 누적합이 같으면 개수 최소
				else if (sum[i][j] == max_val) {
					if ((j - i + 1) < cnt) {
						max_val = sum[i][j];
						temp.first = i;
						temp.second = j;
						cnt = j - i + 1;
					}
				}
			}
		}
		ans += max_val;
		q.push(temp);
	}
	
	cout << ans << '\n';
	while (!q.empty()) {
		cout << q.front().first << ' ' << q.front().second << '\n';
		q.pop();
	}
	
}
void init(){
	memset(sum, 0, sizeof(sum));
	max_val = -1e9;
	temp = { -1, -1 };
	cnt = 1e9;
}
void input() {
	cin >> k;
	rep(x, k) 
		cin >> sum[x][x];
}