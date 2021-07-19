#include <iostream>
#include <algorithm>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n;
char arr[10];
int visited[10];
int num_arr[10];
int max_arr[10];
int min_arr[10];
ll ans_max = -9999999999, ans_min = 9999999999, temp;
void dfs(int num, int idx, int cnt) {
	temp = 0;
	if (idx==n) {
		rep(i, cnt) {
			temp = temp * 10 + num_arr[i];
		}
		if (temp > ans_max) {
			ans_max = temp;
			rep(i, n+1)
				max_arr[i] = num_arr[i];
		}
		if (temp < ans_min) {
			ans_min = temp;
			rep(i, n+1)
				min_arr[i] = num_arr[i];
		}
		return;
	}

	if (arr[idx] == '>') {
		for (int i = num - 1; i >= 0;i--) {
			if (!visited[i]) {
				visited[i] = 1;
				num_arr[cnt] = i;
				dfs(i, idx + 1, cnt + 1);
				visited[i] = 0;
			}
		}
	}
	else {
		for (int i = num + 1; i <= 9; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				num_arr[cnt] = i;
				dfs(i, idx + 1, cnt + 1);
				visited[i] = 0;
			}
		}
	}
}
int main() {
	cin >> n;
	rep(i, n)
		cin >> arr[i];
	rep(i, 10) {
		visited[i] = 1;
		num_arr[0] = i;
		dfs(i, 0, 1);
		visited[i] = 0;
	}
	rep(i, n+1)
		cout << max_arr[i];
	cout << '\n';
	rep(i, n+1)
		cout << min_arr[i];
}