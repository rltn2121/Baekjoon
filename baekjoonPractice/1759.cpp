#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
char arr[16];
char ans[16];
int l, c;
// 모음 최소 1개
// 자음 최소 2개
void dfs(int idx, int step) {
if (step == l) {
	int cnt1 = 0, cnt2 = 0;
	rep(i, l) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
			cnt1++;
		else
			cnt2++;
		// 조건 만족하면 바로 출력
		if (cnt1 >= 1 && cnt2 >= 2) {
			rep(i, l)
				cout << ans[i];
			cout << '\n';
			return;
		}
	}
	return;
}
	for (int i = idx; i < c; i++) {
		ans[step] = arr[i];
		dfs(i + 1, step + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	rep(i, c)
		cin >> arr[i];
	sort(arr, arr + c);
	dfs(0, 0);
}