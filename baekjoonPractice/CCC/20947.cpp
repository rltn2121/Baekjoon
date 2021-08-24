#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n;
char arr[2001][2001];
void input();
void print();
void findX();
void findO();
void addBomb(int x, int y) {
	// ����
	int i = y + 1;
	while (arr[x][i] == '.')
		arr[x][i++] = 'B';
	// ����
	i = y - 1;
	while (arr[x][i] == '.')
		arr[x][i--] = 'B';
	// ����
	i = x - 1;
	while (arr[i][y] == '.')
		arr[i--][y] = 'B';
	// �Ʒ���
	i = x + 1;
	while (arr[i][y] == '.')
		arr[i++][y] = 'B';
}
void removeBomb(int x, int y) {
	// ����
	int i = y + 1;
	while (arr[x][i] == 'B'|| arr[x][i] == '.')
		arr[x][i++] = '.';
	// ����
	i = y - 1;
	while (arr[x][i] == 'B'|| arr[x][i] == '.')
		arr[x][i--] = '.';
	// ����
	i = x - 1;
	while (arr[i][y] == 'B'|| arr[i][y] == '.')
		arr[i--][y] = '.';
	// �Ʒ���
	i = x + 1;
	while (arr[i][y] == 'B'|| arr[i][y] == '.')
		arr[i++][y] = '.';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	findX();
	findO();
	print();
}
void input(){
	cin >> n;
	rep(i, n) {
		rep(j, n)
			cin >> arr[i][j];
	}
}
void print(){
	rep(i, n) {
		rep(j, n)
			cout << arr[i][j];
		cout << '\n';
	}
}
void findX(){
	rep(i, n) {
		rep(j, n) {
			if (arr[i][j] == 'X')
				addBomb(i, j);
		}
	}
}
void findO(){
	rep(i, n) {
		rep(j, n) {
			if (arr[i][j] == 'O')
				removeBomb(i, j);
		}
	}
}