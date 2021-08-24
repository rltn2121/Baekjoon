#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, arr[101];
bool notPrime[1000001];
int primeCnt[100][78500];
int primeSum[78500];
vector<int> prime;
void div(int idx);
void getPrime();
int power(int x, int n);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getPrime();

	cin >> n;
	rep(i, n) {
		cin >> arr[i];
		div(i);
	}

	int gcd = 1;
	int moveCnt = 0;
	for (int i = 0; i < prime.size(); i++) {
		if (primeSum[i] == 0) continue;
		int totalCnt = primeSum[i];	// i번째 소수의 전체 개수
		int cntPerN = totalCnt / n;	// 하나당 필요한 개수
		if (cntPerN == 0) continue;
		gcd *= power(prime[i], cntPerN);

		// 모든 숫자 살펴보기
		for (int j = 0; j < n; j++) {
			int nowCnt = primeCnt[j][i];
			if (nowCnt < cntPerN)
				moveCnt += (cntPerN - nowCnt);
		}
	}

	cout << gcd << ' ' << moveCnt;

}

void div(int idx) {
	int x = arr[idx];
	rep(i, prime.size()) {
		int p = prime[i];
		if (x == 1) return;
		while (x % p == 0) {
			x /= p;
			primeCnt[idx][i]++;
			primeSum[i]++;
		}
	}
}

void getPrime() {
	notPrime[1] = 1;
	for (int i = 2; i < 1000000; i++) {
		if (notPrime[i]) continue;
		prime.push_back(i);
		for (int j = i + i; j < 1000000; j += i)
			notPrime[j] = 1;
	}
}

int power(int x, int n) {
	if (n == 0) return 1;
	return x * power(x, n - 1);
}