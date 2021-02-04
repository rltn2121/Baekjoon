#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
using namespace std;
struct cmp {
	bool operator()(const pii& a, const pii& b) {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};
priority_queue<pii, vector<pii>, cmp> pq;
int n;
pii arr[200001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++) 
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr+n);
	// 배열 -> 시작 시간 오름차순
	// pq -> 종료 시간 오름차순
	// pq의 개수 -> 강의실 개수
	pq.push(arr[0]);
	int cnt = 1;
	for (int i = 1; i < n;i++) {
		if (arr[i].first >= pq.top().second)
			pq.pop();
		pq.push(arr[i]);
	}
	cout << pq.size();
}