#include <iostream>
using namespace std;
int cnt[20];
int n;
void init_cnt() {
	cnt[0] = 1;
	for (int i = 1; i < n; i++)
		cnt[i] = 2 * cnt[i - 1] + 1;
}
void hanoi(int n, int from, int to, int temp) {
	if (n == 1)	{
		cout << from << ' ' << to << '\n';
		return;
	}
	hanoi(n - 1, from, temp, to);
	cout << from << ' ' << to << '\n';
	hanoi(n - 1, temp, to, from);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	init_cnt();
	cout << cnt[n - 1] << '\n';
	if (n == 1)
		cout << 1 << ' ' << 3;
	else 
		hanoi(n, 1, 3, 2);
}