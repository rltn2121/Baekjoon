#include <iostream>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
struct Info {
	long long n;
	int idx;
};

struct cmp {
	bool operator()(Info a, Info b) {
		return a.n > b.n;
	}
};
priority_queue<Info, vector<Info>, cmp> pq;
int k, n;
int arr[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> n;
	rep(i, k) {
		cin >> arr[i];
		pq.push(Info{ arr[i], i });
	}

	int cnt = 1;
	while (cnt < n) {
		Info now = pq.top(); pq.pop();
		for (int i = 0; i < k; i++) {
			int prod = now.n * arr[i];
			pq.push(Info{ prod, i });
			if (now.n % arr[i] == 0) break;
		}
		cnt++;
	}

	cout << pq.top().n;
}