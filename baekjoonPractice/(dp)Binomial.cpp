#include <iostream>
using namespace std;
int binom[100][100] = { -1, };

// 1. recursion
/*int binomial(int n, int k) {
	if (n == k || k == 0)
		return 1;
	else if (binom[n][k] > -1) // binom[n][k]�� �̹� �����ִٸ�
		return binom[n][k];
	else
	{
		binom[n][k] = binomial(n - 1, k) + binomial(n - 1, k - 1);
		return binom[n][k];
	}
}*/

// 2. bottom-up
int binomial(int n, int k)
{
	for (int i = 0; i <= n; i++) {
		// nCk���� k�� n���� Ŭ �� ���� ������ j <= i ��� ���� �ʿ�
		for (int j = 0; j <= k && j <= i; j++) {
			if (j == 0 || i == j)
				binom[i][j] = 1;
			else
				binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
		}
	}
	return binom[n][k];
}