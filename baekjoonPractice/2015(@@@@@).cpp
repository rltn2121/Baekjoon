#include <iostream>
#include <map>
using namespace std;
long long n, k, cnt;
long long p[200001];
map<long long, int> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i] += p[i - 1];
	}

	for (int i = 1; i <=n; i++) {
		// 1) 1~i 까지 합이 k일 때
		if (p[i] == k)
			cnt++;

	/*     2) 
		p[e] - p[s] == k
		p[s] == p[e] - k
		(p[e] - k)가 m의 원소에 포함되면
		cnt에 개수 더하기
	*/
		cnt += m[p[i] - k];

		// 3)
		// for문 밖에서 전부 초기화 시키면 뒤에 결과까지 반영하게됨, 중복
		// for문 시작에서 초기화 시키면 현재 i일 때 값이 중복
		// for문 끝에서 초기화 시켜야 중복 안됨
		m[p[i]]++;
	}
	cout << cnt;
}