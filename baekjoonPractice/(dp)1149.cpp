#include <iostream>
using namespace std;


int main() {
	int num;
	scanf_s("%d", &num);

	int cost[1000][3];

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			scanf_s("%d", &cost[i][j]);
		}
	}

	for (int i = 1; i < num; i++) {
		cost[i][0] += (cost[i - 1][1] < cost[i - 1][2]) ? cost[i - 1][1] : cost[i - 1][2];
		cost[i][1] += (cost[i - 1][0] < cost[i - 1][2]) ? cost[i - 1][0] : cost[i - 1][2];
		cost[i][2] += (cost[i - 1][0] < cost[i - 1][1]) ? cost[i - 1][0] : cost[i - 1][1];
	}

	int minCost = cost[num][0];

	for (int i = 0; i < 3; i++)
	{
		if (cost[num][i] < minCost)
			minCost = cost[num][i];
	}

	cout << minCost;

}