#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, k, arr[201], cnt, ans;
int visited[201];
// �κ��� �����̴� ���
// 1. ��Ʈ�� ������ �� ���� ������
// 2. ��Ʈ ȸ���� �Ŀ� �κ��� ������ ������
void rotate() {
	int temp = arr[2 * n - 1];
	for (int i = 2 * n - 1; i > 0; i--) 
		arr[i] = arr[i-1];
	for (int i = n - 1; i > 0; i--)
		visited[i] = visited[i - 1];
	visited[0] = 0;
	arr[0] = temp;
 }
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	rep(i, 2 * n)
		cin >> arr[i];
	while (cnt < k) {
		ans++;
		// 1. ��Ʈ �� ĭ ȸ��
		rotate();
		// 2. �κ� �̵�
		visited[n - 1] = 0;	// ���� �� �κ��� �ٴ�����
		for (int i = n - 2; i >= 0; i--) {
			if (visited[i] && !visited[i + 1] && arr[i + 1] > 0) {
				visited[i + 1] = 1;
				visited[i] = 0;
				arr[i + 1]--;
				if (arr[i + 1] == 0)
					cnt++;
			}
		}
		// 3. �ö󰡴� ��ġ�� �κ� �ø���
		if (!visited[0] && arr[0] > 0) {
			visited[0] = 1;
			arr[0]--;
			if (arr[0] == 0)
				cnt++;
		}
	}
	cout << ans;
}