
//���Ϳ��� ���Ҹ� ã��, �����, ���� ���Ҹ� �ϳ��� ��ܿ��� ���� ��� O(n)�Դϴ�.���� �� ���� �ð��� O(n ^ 2)���� �е������� �ð��� �����մϴ�.
// trie
// ���� �� ����Ž��
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