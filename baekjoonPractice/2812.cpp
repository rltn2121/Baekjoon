#include <iostream>
#include <deque>
using namespace std;
int n, k, idx;
string str;
deque<char> d;
// 내 앞에 나보다 더 큰게 있으면 그거 삭제

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	cin >> str;
	
	idx = 0;
	while (idx < str.length()) {
		while (k>0 && !d.empty() && d.back() < str[idx]) {
			d.pop_back();
			k--;
		}
		d.push_back(str[idx++]);

	}
	// while에서 k가 0까지 감소하지 않는 경우 때문에
	// 출력할 때 남은 k만큼 빼서 출력
	while (k--)
		d.pop_back();
	for (char c : d)
		cout << c;
}