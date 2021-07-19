#include <iostream>
using namespace std;
int a, b, c;
int arr[51][51][51];

int func(int x, int y, int z) {
	if (x <= 0 || y <= 0 || z <= 0) 
		return 1;

	int& ret = arr[x][y][z];
	if (ret != 0)
		return ret;

	if (x > 20 || y > 20 || z > 20) 
		ret = func(20, 20, 20);

	else if (x < y && y < z)
		ret = func(x, y, z - 1) + func(x, y - 1, z - 1) - func(x, y - 1, z);

	else
		ret = func(x - 1, y, z) + func(x - 1, y - 1, z) + func(x - 1, y, z - 1) - func(x - 1, y - 1, z - 1);
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) 
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << func(a,b,c)<< '\n';
	}
}