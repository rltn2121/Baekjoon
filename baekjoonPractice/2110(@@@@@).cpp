#include <iostream>
#include <algorithm>
using namespace std;
int n, c;
int x[200000];
int cnt;
int counter(int dist) {
	cnt = 1;
	int point = x[0];
	for (int i = 1; i < n; i++) {
		if (x[i] - point >= dist) {
			cnt++;
			point = x[i];
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	sort(x, x + n);

	int min_dist = 1;
	int max_dist = x[n-1]-x[0];
	int answer = 0;
	while (min_dist <= max_dist) {
		int mid = (min_dist + max_dist) / 2;
		cnt = counter(mid);

		if (cnt < c)
			max_dist = mid-1;
		else if (cnt >= c) {
			min_dist = mid + 1;
			answer = max(answer, mid);
		}
	}
	cout << answer << endl;
}