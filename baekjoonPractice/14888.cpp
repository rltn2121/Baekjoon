#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int n;
int arr[11];
int op[4];
int max_val = -987654321;
int min_val = 987654321;

// cnt: ���� Ƚ��
void dfs(int temp_val, int cnt) {
	if (cnt == n - 1) {
		min_val = min(min_val, temp_val);
		max_val = max(max_val, temp_val);
		return;
	}

	// ��Ʈ��ŷ �κ�
	for (int i = 0;i < 4;i++) {		
		if (op[i] != 0) {
			--op[i];			// ����� �����ڴ� ���� ������
			if (i == 0) 
				dfs(temp_val + arr[cnt + 1], cnt+1);
			else if(i == 1)
				dfs(temp_val - arr[cnt + 1], cnt + 1);
			else if (i == 2)
				dfs(temp_val * arr[cnt + 1], cnt + 1);
			else if (i == 3)
				dfs(temp_val / arr[cnt + 1], cnt + 1);
			++op[i];			// ���� Ž���� ���ؼ� ������ ���� ����
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	dfs(arr[0], 0);
	cout << max_val << '\n' << min_val;
}
