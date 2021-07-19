#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[9][9], zero_cnt;
bool visited_horizon[10][10];
bool visited_vertical[10][10];
bool visited_square[10][10];
int getSquareNum(int i, int j) {
	if (i >= 0 && i < 3) {
		if (j >= 0 && j < 3) 
			return 0;
		
		else if (j >= 3 && j < 6) 
			return 1;
		
		else if (j >= 6 && j < 9) 
			return 2;
		
	}
	else if (i >= 3 && i < 6) {
		if (j >= 0 && j < 3) 
			return 3;
		
		else if (j >= 3 && j < 6) 
			return 4;
		
		else if (j >= 6 && j < 9) 
			return 5;
		
	}
	else if (i >= 6 && i < 9) {
		if (j >= 0 && j < 3) 
			return 6;
		
		else if (j >= 3 && j < 6) 
			return 7;
		
		else if (j >= 6 && j < 9) 
			return 8;
	}
}

bool isDuplicated(int i, int j, int x) {
	int k = getSquareNum(i, j);
	if (visited_horizon[i][x]) return 1;
	if (visited_vertical[j][x]) return 1;
	if (visited_square[k][x]) return 1;
	return 0;
}

void visit(int i, int j, int x, bool val) {
	int k = getSquareNum(i, j);
	visited_horizon[i][x] = val;
	visited_vertical[j][x] = val;
	visited_square[k][x] = val;
}

void print() {
	rep(i, 9) {
		rep(j, 9)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}

void dfs(int row) {
	if (zero_cnt == 0) {
		print();
		exit(0);
	}

	int i, j, x;
	for (i = row; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (arr[i][j] == 0) {
				for (x = 1; x <= 9; x++) {
					if (!isDuplicated(i, j, x)) {
						arr[i][j] = x;
						visit(i, j, x, 1);
						zero_cnt--;
						dfs(i);
						arr[i][j] = 0;
						visit(i, j, x, 0);
						zero_cnt++;
					}
				}
				if (x == 10) return;
			}
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	rep(i, 9) {
		rep(j, 9) {
			int x;
			cin >> x;
			arr[i][j] = x;
			if (x == 0)
				zero_cnt++;
			int k = getSquareNum(i, j);
			visited_horizon[i][x] = 1;
			visited_vertical[j][x] = 1;
			visited_square[k][x] = 1;
		}
	}

	dfs(0);
}