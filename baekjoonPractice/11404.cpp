#include <iostream>
using namespace std;

int main() {
	int city;
	int bus;
	
	scanf_s("%d %d", &city, &bus);

	int fromTo[101][101];
	for (int i = 0; i <= city; i++) {
		for (int j = 0; j <= city; j++)
		{
			if (i == j)
				fromTo[i][j] = 0;
			else
				fromTo[i][j] = 999999;
		}
	}

	int from=0;
	int to=0;
	int cost=0;
	for (int i = 1; i <= bus; i++) {
		cin >> from >> to >> cost;
		if(cost < fromTo[from][to])
			fromTo[from][to] = cost;
	}

	for (int visit = 1; visit <= city; visit++) {
		for (int start = 1; start <= city; start++) {
			for (int end = 1; end <= city; end++) {
				if (fromTo[start][visit] + fromTo[visit][end] < fromTo[start][end])
					fromTo[start][end] = fromTo[start][visit] + fromTo[visit][end];
			}
		}
	}

	for (int i = 1; i <= city; i++) {
		for (int j = 1; j <= city; j++)
		{
			if (fromTo[i][j] == 999999)
				fromTo[i][j] = 0;
			printf("%d ", fromTo[i][j]);
		}
		printf("\n");
	}
}