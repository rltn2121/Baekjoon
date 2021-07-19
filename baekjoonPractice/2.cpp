//#include <iostream>
//#include <queue>
//#include <cstring>
//#define rep(i,n) for(int i=0;i<n;i++)
//using namespace std;
//int t, l;
//string a, b, filter, filter_rev;
//int visited[1000000];	// 0: 아무것도 안함, 1: queue에 삽입 완료, 2: 분석 완료
//
//void init() {
//	a = "";
//	b = "";
//	filter_rev = "";
//	memset(visited, 0, sizeof(visited));
//}
//void setDigit(string ta, string tb) {
//	if (ta.length() > tb.length()) {
//		a = ta;
//		for (int i = 0; i < ta.length() - tb.length(); i++)
//			b.append("0");
//		b.append(tb);
//	}
//	else {
//		b = tb;
//		for (int i = 0; i < tb.length() - ta.length(); i++)
//			a.append("0");
//		a.append(ta);
//	}
//}
//int strToInt(string a) {
//	int ret = 0;
//	for (char c : a) 
//		ret = ret * 10 + (c - '0');
//	return ret;
//}
//int func() {
//	queue<string> q;
//	int ret = 1;
//	int size = 0;
//	q.push(a);
//	while (!q.empty()) {
//		size = q.size();
//		while (size--) {
//			string top = q.front();
//			q.pop();
//			int sti_top = strToInt(top);
//			if (visited[sti_top] == 2) continue;		// 2: 분석 완료
//
//			for (int i = 0; i <= top.length() - l; i++) {
//				string now = top;
//				string now_rev = top;
//				
//				bool this_filter_possible = true;
//				bool this_filter_rev_possible = true;
//				for (int j = 0; j < filter.length(); j++) {
//					// 필터 정방향
//					if (this_filter_possible) {
//						if (filter[j] == '+') {
//							if (now[i + j] == '9') 
//								this_filter_possible = false;
//							else
//								now[i + j]++;
//						}
//						else if (filter[j] == '-') {
//							if (now[i + j] == '0') 
//								this_filter_possible = false;
//							else
//								now[i + j]--;
//						}
//					}
//
//					// 필터 역방향
//					if (this_filter_rev_possible) {
//						if (filter_rev[j] == '+') {
//							if (now_rev[i + j] == '9') 
//								this_filter_rev_possible = false;
//							else
//								now_rev[i + j]++;
//						}
//						else if (filter_rev[j] == '-') {
//							if (now_rev[i + j] == '0') 
//								this_filter_rev_possible = false;
//							else
//								now_rev[i + j]--;
//						}
//					}
//				}
//
//				int sti_b = strToInt(b);
//				if (this_filter_possible) {
//					int sti_now = strToInt(now);
//					if (sti_now == sti_b)
//						return ret;
//					if (visited[sti_now] == 0) {
//						visited[sti_now] = 1;
//						q.push(now);
//					}
//				}
//			
//				if (this_filter_rev_possible) {
//					int sti_now_rev = strToInt(now_rev);
//					if (sti_now_rev == sti_b)
//						return ret;
//					if (visited[sti_now_rev] == 0) {
//						visited[sti_now_rev] = 1;
//						q.push(now_rev);
//					}
//				}
//				
//			}
//			visited[sti_top] = 2;	// 2: 분석 완료
//		}
//		ret++;
//	}
//	return -1;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> t;
//	rep(idx, t) {
//		init();
//		string ta, tb;
//		cin >> ta >> tb >> l >> filter;
//		for (int j = filter.length() - 1; j >= 0; j--)
//			filter_rev += filter[j];
//		setDigit(ta, tb);
//		cout << "#" << idx + 1 << ' ' << func() << '\n';
//	}
//}
//
