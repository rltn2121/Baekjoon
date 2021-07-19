#include <iostream>
#define ll long long
using namespace std;
ll dist[100000];
ll price[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++)
		cin >> dist[i];

	for (int i = 0; i < n; i++)
		cin >> price[i];

	int minIdx = 0;
	ll min = price[0];

	ll total_price = 0;
	for (int i = 0; i < n; i++) {
		if (price[i] < min) 
			min = price[i];
		total_price += min * dist[i];
	}
	cout << total_price;
}