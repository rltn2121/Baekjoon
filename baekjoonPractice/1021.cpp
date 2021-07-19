//#include <iostream>
//#include <deque>
//#define rep(i,n) for(int i =0; i<n; i++) 
//using namespace std;
//deque<int> dq;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int n, m;
//	cin >> n >> m;
//	rep(i, n)
//		dq.push_back(i + 1);
//	int next;
//	int cnt = 0;
//	int size = dq.size();
//	int pos;
//	rep(i, m) {
//		cin >> next;
//		// 위치 찾기
//		for (int i = 0; i < dq.size(); i++) {
//			if (dq[i] == next) {
//				pos = i;
//				break;
//			}
//		}
//		while (dq.front() != next) {
//			cnt++;
//			// 뒤에꺼 앞으로
//			if (pos > size / 2) {
//				dq.push_front(*(dq.end() - 1));
//				dq.pop_back();
//			}
//			// 앞에꺼 뒤로
//			else {
//				dq.push_back(dq.front());
//				dq.pop_front();
//			}
//		}
//		dq.pop_front();
//		size--;
//	}
//	cout << cnt;
//}