/*
map, set -> 레드블랙 트리라는 자료구조를 사용
이는 시간복잡도는 로그를 보장해주지만 상수가 매우 큰 자료구조
특히 삽입 / 삭제 연산에서 상당히 많은 작업이 들어갈 수 있음
입력을 한 번에 받고 나중에 정렬하는 편이 몇 배는 더 빠름
*/
#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0; i<n; i++)
using namespace std;
int n, m, a;
int pos[10000001];
int neg[10000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) {
		cin >> a;
		if (a >= 0)
			pos[a]++;
		else
			neg[-a]++;
	}

	cin >> m;
	rep(i, m) {
		cin >> a;
		if (a >= 0)
			cout << pos[a] << ' ';
		else
			cout << neg[-a] << ' ';
	}
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define rep(i,n) for(int i = 0; i<n; i++)
//using namespace std;
//vector<int> v;;
//int n, m, a;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> n;
//	
//	rep(i,n){
//		cin >> a;
//		v.push_back(a);
//	}
//	sort(v.begin(), v.end());
//	cin >> m;	
//	rep(i,m){
//		cin >> a;
//		cout << upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a)<< ' ';
//	}
//}

