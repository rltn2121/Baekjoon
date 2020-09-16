
//벡터에서 원소를 찾고, 지우고, 뒤의 원소를 하나씩 당겨오는 것이 모두 O(n)입니다.따라서 총 수행 시간이 O(n ^ 2)으로 압도적으로 시간이 부족합니다.
// trie
// 정렬 후 이진탐색
// map, set
#include <iostream>
#include <set>
using namespace std;
set<string> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string name, state;
		cin >> name;
		cin.ignore();
		cin >> state;

		if (state == "enter")
			s.insert(name);
		else
			s.erase(name);
	}
	for (auto i = s.rbegin(); i != s.rend(); i++)
		cout << *i << '\n';
}