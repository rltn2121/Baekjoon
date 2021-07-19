#include <iostream>
#include <vector>
using namespace std;
int sequence[101];
vector<int> v;
bool exist(int x) {
	if (v.empty())
		return false;

	for (int i : v) {
		if (i == x)
			return true;
	}
	return false;
}

void remove(int x) {
	for (auto it = v.begin(); it != v.end(); it++) {
		if (*it == x) {
			v.erase(it);
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k;
	cin >> n>>k;
	for (int i = 0; i < k; i++) 
		cin >> sequence[i];

	int ans = 0;
	for (int i = 0; i < k; i++) {
		int now = sequence[i];
		// 사용 중이면 패스
		if (exist(now)) continue;

		// 자리 남으면 연결
		if (v.size() < n) 
			v.push_back(now);
		
		else {
			int del_num = 0;	// 뽑을 콘센트 번호
			int del_idx = -1;	// 뽑을 콘센트 idx
			int cur_idx = -1;	// 현재 콘센트 idx
			for (int x : v) {
				int j = 0;
				for (j= i + 1; j < k; j++) {
					// 연결된 콘센트가 나중에 쓰이면 순서 비교 위해 idx 저장
					if (x == sequence[j]) {
						cur_idx = j;
						break;
					}
				}

				// 안쓰는거 찾으면 바로 뽑아버리기
				if (j == k) {
					del_num = x;
					break;
				}

				// 더 늦게 뽑힌거 찾기
				if (cur_idx > del_idx) {
					del_idx = cur_idx;
					del_num = x;
				}
			}

			ans++;
			remove(del_num);
			v.push_back(sequence[i]);
		}
	}
	cout << ans;
}