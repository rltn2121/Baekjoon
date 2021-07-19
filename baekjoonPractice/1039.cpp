/*
ó�� ���ٹ�: ��Ʈ��ŷ
������: �ߺ� üũ ���ؼ� �ð��ʰ�

�ٸ� ���ٹ�: bfs
�ذ��: cnt���� �ߺ�üũ
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
string str;
queue<string> q;
bool visited[1000000];
int n, m, k;
int ans = -1;

int strToInt() {
	int ret = 0;
	for (int i = 0; i < m; i++){
		ret *= 10;
		ret += (str[i]-'0');
	}
	return ret;
}

void swap(int i, int j) {
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void bfs() {
	int cnt = 0;
	q.push(str);
	while (cnt < k) {
		int q_size = q.size();
		while (q_size--) {
			string now = q.front();
			q.pop();

			for (int i = 0; i < m; i++) {
				for (int j = i + 1; j < m; j++) {
					str = now;
					swap(i, j);
					int sti = strToInt();
					if (!visited[sti]) {
						visited[sti] = 1;
						q.push(str);
					}
				}
			}

		}
		cnt++;
		memset(visited, 0, sizeof(visited));
	}

	while (!q.empty()) {
		str = q.front();
		int sti = strToInt();
		ans = max(ans, sti);
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> str >> k;
	m = str.length();
	
	int input = strToInt();

	if (input == 1000000) {
		cout << input;
		return 0;
	}

	if ((input >= 1 && input <= 9) || (input < 100 && input % 10 == 0)) {
		cout << -1;
		return 0;
	}

	bfs();
	cout << ans;
}