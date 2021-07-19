#include <iostream>
#include <deque>
using namespace std;
int n, k, idx;
string str;
deque<char> d;
// �� �տ� ������ �� ū�� ������ �װ� ����

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
	// while���� k�� 0���� �������� �ʴ� ��� ������
	// ����� �� ���� k��ŭ ���� ���
	while (k--)
		d.pop_back();
	for (char c : d)
		cout << c;
}