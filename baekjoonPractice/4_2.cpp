#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int t, n, k, ans = 987654321;
int one_cnt_k[100001];
vector<string> arr;
int key[100001];
void move(int i) {
	int origin_key = key[i];
	int temp = 0;
	if ((key[i] & (1 << (k - 1))) != 0)
		temp = 1;
	int mask = (1 << k) - 1;
	key[i] = ((key[i] << 1) + temp) & mask;

	for (int j = 0; j < k; j++) {
		int origin_bit = (origin_key & (1 << (k - j - 1)));
		int new_bit = (key[i] & (1 << (k - j - 1)));
		//cout << origin_bit << '\t' << new_bit << '\n';
		if (origin_bit != 0 && new_bit == 0)
			one_cnt_k[j]--;
		else if (origin_bit == 0 && new_bit != 0)
			one_cnt_k[j]++;
	}

}

bool check() {
	rep(i, k) {
		if (one_cnt_k[i] == n)
			return true;
	}
	return false;
}

int dfs(int row, int cnt) {
	// 맞는지 검사
	if (check()) {
		ans = min(ans, cnt);
		return ans;
	}
	// 종료조건
	if (row >= n) return -1;

	// 백트래킹
	// ※ 오른쪽으로 1번 옮긴거 == 왼쪽으로 3번 옮긴거
	for (int i = 1; i <= k; i++) {
		move(row);
		cnt += min(i, k - i);
		//print(row);

		dfs(row + 1, cnt);
		cnt -= min(i, k - i);
	}
}
void init_one_cnt() {
	rep(i, n) {
		rep(j, k) {
			if (key[i] & (1 << (k - j - 1)))
				one_cnt_k[j]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	rep(idx, t) {
		arr.clear();
		memset(one_cnt_k, 0, sizeof(arr));
		memset(key, 0, sizeof(arr));
		ans = 987654321;
		cin >> n >> k;
		rep(i, k) {
			string x;
			cin >> x;
			arr.push_back(x);
		}


		rep(i, n) {
			rep(j, k)
				key[i] = (key[i] << 1) + (arr[j][i] - '0');
		}

		init_one_cnt();
		dfs(0, 0);
		cout << '#' << idx + 1 << ' ' << ans;
	}
}