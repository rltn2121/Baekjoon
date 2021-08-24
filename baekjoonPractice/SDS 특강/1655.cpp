// ����: https://gpfatp.blogspot.com/2019/07/boj-1655.html
#include <iostream>
#include <queue>
using namespace std;
int n, x;
priority_queue<int> left_max_pq;
priority_queue<int, vector<int>, greater<int> > right_min_pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> x;
		
		// ����, ���������� ������ ���� ����
		// �� �������� ���� ����						(1 2 3 4 5 6 7 8 9 10)
		// ����   -> ���� ū ���� �߰���	 (max_pq)	1  2 3 4 "5" | "6" 7 8 9  10
		// ������ -> ���� ���� ���� �߰���	 (min_pq)

		// 1. ����, ������ �����ư��鼭 ���� (���� ����)
		if (left_max_pq.size() == right_min_pq.size())
			left_max_pq.push(x);
		else
			right_min_pq.push(x);

		// 2. ������ ���ڰ� ���� ���ں��� �׻� Ŀ���� (���Ƶ� ��)
		// �������� �����̱� ����
		// ���� ���� > ������ ����: �ٲ���
		if (!left_max_pq.empty() && !right_min_pq.empty() && right_min_pq.top() < left_max_pq.top()) {
			int a = left_max_pq.top(); left_max_pq.pop();
			int b = right_min_pq.top(); right_min_pq.pop();

			right_min_pq.push(a);
			left_max_pq.push(b);
		}
		cout << left_max_pq.top() << '\n';
	}
}

