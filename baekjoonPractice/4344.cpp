#include <iostream>
using namespace std;

int main()
{
	int c, num, cnt = 0;
	float sum = 0;
	float score[1000] = { 0 };

	cin >> c;

	while (c > 0)
	{
		num = 0;
		cnt = 0;
		sum = 0;
		cin >> num;

		for (int i = 0; i < num; i++)
		{
			cin >> score[i];
			sum += score[i];
		}

		for (int i = 0; i < num; i++)
		{
			if (score[i] > float(sum) / num)
				cnt++;
		}


		printf("%.3f%%\n", float(cnt) / num * 100);
		c--;
	}

}