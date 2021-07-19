// https://www.acmicpc.net/board/view/25583
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int k, v, e, a, b, arr[20001];
vector<vector<int> > vec;
void dfs(int now) {
	// 현재 정점이 속한 그룹이 없을 때 (0일 때)
	if (!arr[now])
		arr[now] = 1;

	// 현재 정점이 속한 그룹이 있다면
	// 연결된 정점은 무조건 현재 정점과 반대가 되어야 함
	for (int i : vec[now]) {
		if (!arr[i]) {
			arr[i] = (arr[now] == 1 ? 2 : 1);
			dfs(i);
		}
	}
}

bool chk() {
	for (int i = 0; i < vec.size(); i++) {
		for (int j : vec[i]) {		// 나와 연결된 모든 정점 탐색
			if (arr[i] == arr[j])	// 연결된 정점은 무조건 다른 그룹이어야 함
				return false;		// 연결된 정점이 같은 그룹이면 FALSE
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
		// 모든 정점에 대해서 탐색
		for (int i = 0; i < v;i++) {
			// 해당 정점이 속한 그룹이 없으면 (0이면)
			if (!arr[i])
				dfs(i);
		}
		cout << (chk() ? "YES" : "NO") << '\n';
	}
}