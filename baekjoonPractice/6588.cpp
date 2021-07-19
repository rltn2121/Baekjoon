#include <iostream>
#include <vector>
using namespace std;
bool not_prime[1000001];
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// 소수가 아닌 숫자 찾기
	not_prime[1] = 1;
	for (int i = 2;i <= 1000000;i++) {
		if (not_prime[i]) continue;
		for (int j = 2;i * j <= 1000000;j++) 
			not_prime[i * j] = 1;
	}
	// 모든 소수를 벡터에 저장
	for (int i = 3;i <= 1000000;i++) {
		if (!not_prime[i])
			v.push_back(i);
	}
	int n;
	cin >> n;
	while (n != 0) {
		for (int i : v) {
			if (!not_prime[n - i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				break;

			}
		}
		cin >> n;
	}
	
}