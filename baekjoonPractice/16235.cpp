#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int dx[] = {0, -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = {0, -1, 0, 1, -1, 1, -1, 0, 1 };

struct TREE {
	int x;
	int y;
	int age;
};
bool cmp(TREE& a, TREE& b) {
	return a.age < b.age;
}
int n, m, k, arr[11][11], A[11][11];
vector<TREE> tree;
vector<TREE> alive;
queue<TREE> current;
queue<TREE> dead;
queue<TREE> generated;

void spring() {
	while (!current.empty()) {
		TREE t = current.front();
		current.pop();

		int x = t.x;
		int y = t.y;
		if (arr[x][y] >= t.age) {
			arr[x][y] -= t.age;
			t.age++;
			alive.push_back(t);
		}
		else
			dead.push(t);
	}
}
void summer() {
	while (!dead.empty()) {
		TREE t = dead.front();
		dead.pop();
		arr[t.x][t.y] += (t.age / 2);
	}
}
void fall() {
	for (TREE t : alive) {
		if (t.age % 5 == 0) {
			rep(i, 8) {
				int nx = t.x + dx[i];
				int ny = t.y + dy[i];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;	
				current.push(TREE{ nx, ny, 1 });
			}
		}
	}

	for (TREE t : alive) 
		current.push(t);
	
	alive.clear();
}
void winter() {
	rep(i, n) {
		rep(j, n)
			arr[i][j] += A[i][j];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	rep(i, n) {
		rep(j, n) {
			arr[i][j] = 5;
			cin >> A[i][j];
		}
	}
	rep(i, m) {
		int x, y, age;
		cin >> x >> y >> age;
		tree.push_back({ x, y, age });
	}

	sort(tree.begin(), tree.end(), cmp);
	for(TREE t : tree)
		current.push(t);
	
	rep(i, k) {
		spring();
		summer();
		fall();
		winter();
	}
	cout << current.size();
}