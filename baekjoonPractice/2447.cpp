#include <iostream>
#include <cmath>
using namespace std;
char arr[6600][6600];
void star(int x, int y, int size) {
	if (size == 1) {
		arr[x][y] = '*';
		return; 
	}

	for (int i = x; i < x+size; i+=size/3) {
		for (int j = y; j < y+size; j+=size/3) {	
			if (i >= x+size / 3 && i < x+size / 3 * 2 && j >= y+size / 3 && j < y+size / 3 * 2)
				arr[i][j] = ' ';
			else 
				star(i,j,size / 3);
 		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;


	/* �迭 �ʱ�ȭ, �� �κ� �߰� ���ϸ� wrong answer*/
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++)
	//		arr[i][j] = ' ';
	//}

	star(0,0,n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
		cout << '\n';
	}
}