#include <iostream>
using namespace std;
int n, r, c;
int cnt = 0;
void visit(int row, int col, int size) {
	int nextSize = size >> 1;
	if (size == 1) return;
	if (r >= row + nextSize) {
		if (c >= col + nextSize) {
			cnt += nextSize*nextSize * 3;
			visit(row + nextSize, col + nextSize, nextSize);
		}
		else {
			cnt += nextSize * nextSize * 2;
			visit(row + nextSize, col, nextSize);
		}
	}
	else {
		if (c >= col + nextSize) {
			cnt += nextSize * nextSize;
			visit(row, col + nextSize, nextSize);
		}
		else 
			visit(row, col, nextSize);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r >> c;
	visit(0, 0, 1<<n);
	cout << cnt << endl;
}