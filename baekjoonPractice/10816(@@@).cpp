/*
map, set -> ����� Ʈ����� �ڷᱸ���� ���
�̴� �ð����⵵�� �α׸� ������������ ����� �ſ� ū �ڷᱸ��
Ư�� ���� / ���� ���꿡�� ����� ���� �۾��� �� �� ����
�Է��� �� ���� �ް� ���߿� �����ϴ� ���� �� ��� �� ����
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

