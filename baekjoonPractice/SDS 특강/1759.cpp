#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int l, c, ans, m_cnt, j_cnt;
char arr[15];
vector<char> v;
void check(int i, int val) {
	if (arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'e')
		m_cnt += val;
	else
		j_cnt += val;
}
void dfs(int idx, int cnt) {
	if (cnt == l) {
		if (m_cnt >= 1 && j_cnt >= 2) {
			// 모음 1개, 자음 2개
			for (char c : v)
				cout << c;
			cout << '\n';
		}
		return;
			
	}
	for (int i = idx; i < c; i++) {
		v.push_back(arr[i]);
		check(i, 1);
		dfs(i + 1, cnt + 1);
		v.erase(v.end() - 1);
		check(i, -1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> l >> c;
	rep(i, c)
		cin >> arr[i];
	sort(arr, arr + c);
	dfs(0, 0);
}