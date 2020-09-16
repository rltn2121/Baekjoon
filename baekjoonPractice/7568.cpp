#include <iostream>
using namespace std;
class Person {
public:
	int x, y;
	int rank = 1;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Person p[50];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p[i].x = a;
		p[i].y = b;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;

			if (p[i].x < p[j].x&& p[i].y < p[j].y)
				p[i].rank++;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << p[i].rank << ' ';
	}
}