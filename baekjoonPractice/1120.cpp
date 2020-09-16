#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<char> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	v.reserve(50);
	string a, b;
	cin >> a >> b;

	for (char c : a)
		v.push_back(c);
	
	int minIdx = 0;											// A�� ��ĭ �Űܾ� �� ��
	int minDiff = 99999;									// A,B ������ �ּҰ�
	int shift = 0;											// �̵��� Ƚ��
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int diff = 0;
		for (int j = shift; j < v.size(); j++) {
			if (b[j] != v[j])								// �ٸ��� ���ϱ�
				diff++;
		}
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i;
		}
		v.insert(v.begin(), '0');							// ���ڿ� A�� �տ� 0�� �߰��ؼ� ���������� ��ĭ �̵�
		shift++;
	}
	v.clear();
	for (char c : a)
		v.push_back(c);

	// ���ڿ� A�� �տ� �߰�
	for (int i = minIdx - 1; i >= 0; i--) 
		v.insert(v.begin(),b[i]);

	// ���ڿ� A�� �ڿ� �߰�
	for (int i = v.size(); i < b.length(); i++)
		v.push_back(b[i]);

	// A, B�� ���� ���
	int cnt = 0;
	for (int i = 0; i < b.length(); i++) {
		if (v[i] != b[i])
			cnt++;
	}
	cout << cnt << endl;
}