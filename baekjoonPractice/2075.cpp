//#include <iostream>
//#include <map>
//#define rep(i,n) for(int i=0;i<n;i++)
//#define ll long long
//using namespace std;
//int n;
//map<ll, int> m;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> n;
//
//	rep(i, n) {
//		rep(j, n) {
//			int x;
//			cin >> x;
//			m.insert({ x,1 });
//			// n개보다 많으면 가장 작은 수 빼버리기
//			if (m.size()>n) 
//				m.erase((*m.begin()).first);
//		}
//	}
//	cout << (*m.begin()).first;
//}

#include <iostream>
using namespace std;
void s(int& x, int& y) {
	int t;
	t = x;
	x = y;
	y = t;
}
int main() {
	int test[5] = { 1,2,3,4,5 };
	int k = 0;
	s(k, test[k]);
	for (int i = 0; i < 5; i++)
		cout << test[i] << ' ';
	cout << endl << k << endl;
}