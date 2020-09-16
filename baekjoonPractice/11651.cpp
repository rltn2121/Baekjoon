// 1. STL sort 사용법
// 2. scanf_s, cin 속도차이

#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Point {
	int x;
	int y;
} Point;
bool compare(Point a, Point b) {
	if (a.y == b.y)
		return a.x < b.x; 
	else
		return a.y < b.y;
}

int main() {
	int num;
	cin >> num;

	Point *arr = new Point[num];
	for (int i = 0; i < num; i++) {
		scanf_s("%d %d", &arr[i].x, &arr[i].y);
	}
	
	sort(arr, arr + num, compare);

	for (int i = 0; i < num; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	free(arr);
}