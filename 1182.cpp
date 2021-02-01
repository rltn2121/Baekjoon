//#include <iostream>
//#define rep(i,n) for(int i=0;i<n;i++)
//using namespace std;
//int arr[21];
//int n, s;
//int cnt;
//int sum = 0;
//int ans = 0;
// void dfs(int idx, int step) {
//	 // r개 만큼 선택 했으면
//	if (step == cnt) {
//		if (sum == s)
//			ans++;
//		return;
//	}
//	
//	// 백트래킹
//	// 선택하고 되돌려놓기
//	for (int i = idx; i < n; i++) {
//		sum += arr[i];
//		dfs(i + 1, step + 1);
//		sum -= arr[i];
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> n >> s;
//	rep(i, n)
//		cin >> arr[i];
//	
//	// n개 중 r개 고를 때 r값 결정
//	for (int i = 1; i <= n; i++) {
//		cnt = i;
//		dfs(0, 0);
//		sum = 0;
//	}
//	cout << ans;
//}