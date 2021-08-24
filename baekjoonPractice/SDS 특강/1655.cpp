// 참고: https://gpfatp.blogspot.com/2019/07/boj-1655.html
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
		
		// 왼쪽, 오른쪽으로 나눠서 숫자 삽입
		// ● 오름차순 정렬 기준						(1 2 3 4 5 6 7 8 9 10)
		// 왼쪽   -> 제일 큰 값이 중간값	 (max_pq)	1  2 3 4 "5" | "6" 7 8 9  10
		// 오른쪽 -> 제일 작은 값이 중간값	 (min_pq)

		// 1. 왼쪽, 오른쪽 번갈아가면서 삽입 (왼쪽 먼저)
		if (left_max_pq.size() == right_min_pq.size())
			left_max_pq.push(x);
		else
			right_min_pq.push(x);

		// 2. 오른쪽 숫자가 왼쪽 숫자보다 항상 커야함 (같아도 됨)
		// 오름차순 정렬이기 때문
		// 왼쪽 숫자 > 오른쪽 숫자: 바꿔줌
		if (!left_max_pq.empty() && !right_min_pq.empty() && right_min_pq.top() < left_max_pq.top()) {
			int a = left_max_pq.top(); left_max_pq.pop();
			int b = right_min_pq.top(); right_min_pq.pop();

			right_min_pq.push(a);
			left_max_pq.push(b);
		}
		cout << left_max_pq.top() << '\n';
	}
}

