#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
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
	pq.push(arr[0].second);
	for (int i = 1; i < n;i++) {
		if (arr[i].first >= pq.top())
			pq.pop();
		pq.push(arr[i].second);
	}
	cout << pq.size();
}