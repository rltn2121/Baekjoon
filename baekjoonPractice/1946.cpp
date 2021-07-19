#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int, int>
using namespace std;
int t, n, ans;
pii arr[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		rep(i, n)
			cin >> arr[i].first >> arr[i].second;

		sort(arr, arr + n);				// 서류 순위 정렬
		ans++;
		int rank = arr[0].second;		// 면접 순위 최솟값
		for(int i = 1; i<n; i++) {
			if (arr[i].second < rank) {	// 내 앞사람보다 면접 순위 높으면
				rank = arr[i].second;	// 면접 순위 최솟값 갱신
				ans++;					// 뽑힌 사람 수 증가
			}
		}
		cout << ans << '\n';
	}
}