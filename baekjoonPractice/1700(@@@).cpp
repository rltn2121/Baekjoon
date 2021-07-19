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
		// ��� ���̸� �н�
		if (exist(now)) continue;

		// �ڸ� ������ ����
		if (v.size() < n) 
			v.push_back(now);
		
		else {
			int del_num = 0;	// ���� �ܼ�Ʈ ��ȣ
			int del_idx = -1;	// ���� �ܼ�Ʈ idx
			int cur_idx = -1;	// ���� �ܼ�Ʈ idx
			for (int x : v) {
				int j = 0;
				for (j= i + 1; j < k; j++) {
					// ����� �ܼ�Ʈ�� ���߿� ���̸� ���� �� ���� idx ����
					if (x == sequence[j]) {
						cur_idx = j;
						break;
					}
				}

				// �Ⱦ��°� ã���� �ٷ� �̾ƹ�����
				if (j == k) {
					del_num = x;
					break;
				}

				// �� �ʰ� ������ ã��
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