#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n;
int arr[26], ans;
string str;
int power(int x, int n) {
	if (n == 0) return 1;
	return x * power(x, n - 1);
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(j,n) {
		cin >> str;
		rep(i, str.length()) {
			int pos = str.length() - 1 - i;
			arr[str[i]-'A'] += power(10, pos);
		}
	}

	sort(arr, arr + 26, cmp);

	rep(i, 10)
		ans += (arr[i] * (9 - i));
	cout << ans;
}