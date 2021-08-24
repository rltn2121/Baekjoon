#include <iostream>
#define pii pair<int, int>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m;
char arr[101][101];
int init;
pii p1, p2, p3, p4;
int p1_hor, p1_ver, p2_hor, p2_ver;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	rep(i, n) {
		rep(j, m) {
			cin >> arr[i][j];
			if (init==0 && arr[i][j] == '#') {
				init++;
				p1 = { i,j };
			}
			if (init ==1 && arr[i][j] == '.' ) {
				init++;
				p2 = { i,j-1 };
			}
			else if (init == 1 &&  j == m - 1) {
				init++;
				p2 = { i,j};
			}
		}
	}

	int temp = p1.second;
	while (arr[p1.first][temp] == '#') {
		p1_hor++;
		temp++;
	}
	temp = p1.first;
	while (arr[temp][p1.second] == '#') {
		p1_ver++;
		temp++;
	}
	temp = p2.second;
	while (arr[p2.first][temp] == '#') {
		p2_hor++;
		temp++;
	}
	temp = p2.first;
	while (arr[temp][p2.second] == '#') {
		p2_ver++;
		temp++;
	}

	if (p2_ver == 1) cout << "UP";
	else if (p1_ver > p2_ver) cout << "RIGHT";
	else if (p1_ver == p2_ver) cout << "DOWN";
	else if (p1_ver < p2_ver) cout << "LEFT";
}