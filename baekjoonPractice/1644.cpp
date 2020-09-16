#include <iostream>
#include <vector>
using namespace std;
vector<int> prime;
bool arr[4000001];
void eratos(int n) {
	for (int i = 2; i <= n; i++) {
		if (arr[i])
			continue;
		prime.push_back(i);
		for (int j = i * 2; j <= n; j += i)
			arr[j] = true;
	}
}
int sum(int start, int end) {
	int ret = 0;
	for (int i = start; i < end; i++)
		ret += prime[i];
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	eratos(n);

	int start = 0, end = 0;
	int cnt = 0;
	while (start <= end) {
		if (sum(start, end) == n)
			cnt++;
		if (sum(start, end) > n || end == prime.size())
			start++;
		else
			end++;
	}
	cout << cnt << endl;
}