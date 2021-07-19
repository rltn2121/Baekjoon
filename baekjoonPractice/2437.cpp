// https://justicehui.github.io/koi/2018/09/21/BOJ2437/
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1001];
int sum[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++) 
		cin >> arr[i];
	sort(arr, arr + n+1);

	for(int i = 1; i<=n; i++)
		sum[i] = sum[i-1]+arr[i];

	int i = 1;
	for (i = 1; i <= n; i++) {
		if (sum[i - 1] + 1 < arr[i]) 
			break;
		
	}
	cout << sum[i - 1] + 1;
}