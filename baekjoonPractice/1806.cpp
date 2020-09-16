#include <iostream>
using namespace std;
int arr[100001];
int sum[100001];
void initSum(int n) {
	sum[1] = arr[0];
	for (int i = 2; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	initSum(n);
	int start = 0, end = 0;
	int minLength = 987654321;
	while (start <= end) {
		if (sum[end]-sum[start] >= s)
			minLength = (minLength < end - start ? minLength : end - start);
		if (sum[end] - sum[start] >= s || end==n)
			start++;
		else
			end++;
	}
	if (minLength == 987654321)
		minLength = 0;
	cout << minLength << endl;
}

/*
10 10
1 1 1 1 1 1 1 1 1 1*/