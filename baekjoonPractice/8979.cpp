#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> nation[1000];
int n, k;
bool cmp(vector<int> &a, vector<int> &b) {
	return (a[1] == b[1] ? (a[2] == b[2] ? a[3] > b[3] : a[2] > b[2]) : a[1] > b[1]);
}

int func() {
	sort(nation, nation + n, cmp);

	// ���� ó�� ���� index�� 0���� ����
	nation[0].push_back(0);
	int compare_index = 0;
	for (int i = 1; i < n; i++) {
		// ���� index�� �޴� ������ ���� index�� �޴� ������ �ٸ��ٸ�
		if (cmp(nation[compare_index], nation[i])) {
			nation[i].push_back(i);
			// ���� index ����
			compare_index = i;
		}
		// ���� index�� �޴� ������ ���� index�� �޴� ������ ���ٸ�
		else 
			// ���� index ���� ����
			nation[i].push_back(compare_index);
	}

	for (int i = 0; i < n; i++) {
		if (nation[i][0] == k)
			return nation[i][4]+1;
	}
	return -1;
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 0; i<n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		nation[i].push_back(a);
		nation[i].push_back(b);
		nation[i].push_back(c);
		nation[i].push_back(d);
	}

	cout << func() << endl;;
}