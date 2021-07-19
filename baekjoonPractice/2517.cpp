#include <iostream>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mid (s+e)/2
#define pii pair<int, int>
using namespace std;
int n, arr[500001], visited[500001 * 4 + 1];
priority_queue<pii> q;

// 좌표 압축
void getPower() {
	while (!q.empty()) {
		pii now = q.top();
		arr[now.second] = q.size();
		q.pop();
	}
}

int query(int root, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return visited[root];
	return query(root * 2, s, mid, l, r) + query(root * 2 + 1, mid + 1, e, l, r);
}

int update(int root, int s, int e, int idx, int num) {
	if (idx < s || e < idx) return visited[root];
	if (s == e) return visited[root] = num;
	return visited[root] = update(root * 2, s, mid, idx, num) + update(root * 2 + 1, mid + 1, e, idx, num);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		cin >> arr[i];
		q.push({ arr[i], i });
	}
	// 1. 좌표 압축
	getPower();

	int cnt = 0;
	// 2. 세그먼트 트리
	rep(now_rank, n) {
		int now_power = arr[now_rank];			// 1) rank, power 선택
		cnt = query(1, 1, n, 1, now_power - 1);	// 2) 현재 power보다 낮은 것들이 몇 개 나타났는지 체크 (cnt)
		update(1, 1, n, now_power, 1);			// 3) 현재 power 방문처리 (update 1로 변경)
		cout << now_rank - cnt << '\n';			// 4) 출력 (rank – cnt)
	}
}