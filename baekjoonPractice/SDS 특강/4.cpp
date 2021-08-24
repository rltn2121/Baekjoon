//#include <iostream>
//#include <algorithm>
//#include <deque>
//#include <vector>
//#include <cstring>
//#define rep(i,n) for(int i=0;i<n;i++)
//using namespace std;
//int t, n, k, ans = 987654321;
//int one_cnt_k[100001];
//vector<deque<int> > v;
//void toRight(int i) {
//	int x = v[i][v[i].size()-1];
//	v[i].pop_back();
//	v[i].push_front(x);
//}
//
//bool check() {
//	rep(i, k) {
//		if (one_cnt_k[i] == n)
//			return true;
//	}
//	return false;
//}
//
//int dfs(int row, int cnt) {
//	// �´��� �˻�
//	if (check()) {
//		ans = min(ans, cnt);
//		return ans;
//	}
//	// ��������
//	if (row >= n) return -1;
//
//	// ��Ʈ��ŷ
//	// �� ���������� 1�� �ű�� == �������� 3�� �ű��
//	for (int i = 1; i <= k; i++) {
//		toRight(row);
//		cnt+= min(i, k - i);
//		//print(row);
//
//		dfs(row+1, cnt);
//		cnt -= min(i, k - i);
//	}
//}
//void init_one_cnt() {
//	rep(i, k) {
//		rep(j, n) {
//			one_cnt_k[i] += v[j][i];
//		}
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> t;
//	rep(idx, t) {
//		cin >> n >> k;
//		v.resize(n);
//		rep(i, k) {
//			rep(j, n) {
//				char c;
//				cin >> c;
//				v[j].push_back(c-'0');
//			}
//		}
//
//		init_one_cnt();
//		rep(i, k)
//			cout << one_cnt_k[i] << ' ';
//		cout << '\n';
//		dfs(0, 0);
//		cout << '#' << idx + 1 << ' ' << ans;
//	}
//}