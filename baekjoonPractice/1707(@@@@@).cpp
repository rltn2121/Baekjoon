// https://www.acmicpc.net/board/view/25583
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int k, v, e, a, b, arr[20001];
vector<vector<int> > vec;
void dfs(int now) {
	// ���� ������ ���� �׷��� ���� �� (0�� ��)
	if (!arr[now])
		arr[now] = 1;

	// ���� ������ ���� �׷��� �ִٸ�
	// ����� ������ ������ ���� ������ �ݴ밡 �Ǿ�� ��
	for (int i : vec[now]) {
		if (!arr[i]) {
			arr[i] = (arr[now] == 1 ? 2 : 1);
			dfs(i);
		}
	}
}

bool chk() {
	for (int i = 0; i < vec.size(); i++) {
		for (int j : vec[i]) {		// ���� ����� ��� ���� Ž��
			if (arr[i] == arr[j])	// ����� ������ ������ �ٸ� �׷��̾�� ��
				return false;		// ����� ������ ���� �׷��̸� FALSE
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	while (k--) {
		cin >> v >> e;
		memset(arr, 0, sizeof(arr));
		vec.clear();
		vec.resize(v+1);
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		// ��� ������ ���ؼ� Ž��
		for (int i = 0; i < v;i++) {
			// �ش� ������ ���� �׷��� ������ (0�̸�)
			if (!arr[i])
				dfs(i);
		}
		cout << (chk() ? "YES" : "NO") << '\n';
	}
}