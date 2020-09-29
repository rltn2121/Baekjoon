/* 참고: https://youtu.be/Enz2csssTCs*/

#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[10];
bool visited[10];

int n, m;
// k번째에 들어갈 숫자 찾기
void func(int k) {
	// m개 다 찾았으면 출력
	if (k == m) {
		rep(i, m)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	// 순서대로 훑어보기
	for (int i = 1; i <= n; i++) {
		// i번째 추가 안했으면 추가하기
		if (!visited[i]) {
			arr[k] = i;
			visited[i] = true;
			func(k + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	func(0);
}