#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int visited[26];
vector<vector<char> > v;
int n, k, cnt = 5, ans;
string str;
void dfs(int now, int cnt) {
	if (cnt == k) {
		int temp = 0;
		for (vector<char> vec : v) {
			int j;
			// 방문 안 한 글자 있으면 break
			for (j = 0; j < vec.size(); j++) 
				if (!visited[vec[j] - 'a']) break;
			
			// 끝까지 돌았으면 temp++
			if (j == vec.size())
				temp++;
		}
		ans = max(ans, temp);
		return;
	}

	// 백트래킹으로 사용하지 않은 문자 찾기
	for (int i = now; i < 26; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i + 1, cnt + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	v.resize(n);
	// 앞 뒤 4글자 방문
	visited['a' - 'a'] = 1;
	visited['n' - 'a'] = 1;
	visited['t' - 'a'] = 1;
	visited['i' - 'a'] = 1;
	visited['c' - 'a'] = 1;

	// 가운데 글자 입력
	rep(i,n){
		cin >> str;
		for (int j = 4; j < str.size() - 4; j++)
			v[i].push_back(str[j]);
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	dfs(0, cnt);
	cout << ans;
}