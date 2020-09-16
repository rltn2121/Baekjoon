#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	int cnt = 0;
	while (a >0 && b>0) {
		if (a % 2 == 0)
			a /= 2;
		else
		{
			if(a != 1)
				a = (a / 2) + 1;
		}

		if (b % 2 == 0)
			b /= 2;
		else
		{
			if(b != 1)
				b = (b / 2) + 1;
		}
		cnt++;
		if (a == b)
			break;
	}
	cout << cnt-- << endl;
}