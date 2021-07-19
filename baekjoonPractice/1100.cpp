#include <stdio.h>
int main() {
	int cnt;
	char ch;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf_s("%c", &ch);
			if((ch=='F')&&(i%2==0&&j%2==0)|(i%2==1&&j%2==1))
				cnt++;
		}
		scanf_s("%c", &ch);
	}
	printf("%d", cnt);
}