#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[13];
int val[13];
int k;
void dfs(int idx, int cnt) {
	// 종료 조건
	if (cnt == 6) {
		rep(i,6)
			cout << val[i] << ' ';
		cout << '\n';
		return;
	}
	
	// 백트래킹
	// n개 중 6개 뽑아서 나열
	for (int i = idx; i < k; i++) {
		// 현재 값을 배열에 저장
		// cnt는 배열의 인덱스로 사용
		val[cnt] = arr[i];
		dfs(i+1, cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	while (k != 0) {
		rep(i, k)
			cin >> arr[i];

		dfs(0, 0);
		cout << '\n';
		cin >> k;
	}
}