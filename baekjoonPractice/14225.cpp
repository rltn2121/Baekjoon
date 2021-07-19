#include <iostream>
#include <algorithm>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, arr[21];
bool visited[2000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, n)
		cin >> arr[i];
	sort(arr, arr + n);

	int mask = 0;
	while (mask < (1 << n)) {
		int temp = 0;
		rep(i,n) {
			int x = (mask >> i) & 1;	// ��Ʈ����ũ �̿�
			temp += x * arr[i];			// ��� ���� ã�ƺ�
		}
		visited[temp] = 1;				// ������� ���� üũ
		mask++;
	}
	rep(i, 2000001) {
		if (!visited[i]) {				// üũ���� ���� ù ��° ���� ���
			cout << i;
			break;
		}
	}
}