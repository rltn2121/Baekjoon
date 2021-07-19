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
		// 1) 1~i ���� ���� k�� ��
		if (p[i] == k)
			cnt++;

	/*     2) 
		p[e] - p[s] == k
		p[s] == p[e] - k
		(p[e] - k)�� m�� ���ҿ� ���ԵǸ�
		cnt�� ���� ���ϱ�
	*/
		cnt += m[p[i] - k];

		// 3)
		// for�� �ۿ��� ���� �ʱ�ȭ ��Ű�� �ڿ� ������� �ݿ��ϰԵ�, �ߺ�
		// for�� ���ۿ��� �ʱ�ȭ ��Ű�� ���� i�� �� ���� �ߺ�
		// for�� ������ �ʱ�ȭ ���Ѿ� �ߺ� �ȵ�
		m[p[i]]++;
	}
	cout << cnt;
}