#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<pair<int, int> > > time(100005);
int table[100005] = { 0, };

int main() {
	int n;
	cin >> n;
	int a, b;
	int maxHour = -1;
	for(int i = 0; i<n; i++){
		cin >> a >> b;
		int hour = b - a;
		maxHour = max(maxHour, hour);
		time[hour].push_back(make_pair(a, b));
	}
	int count = 0;
	bool possible = true;

	for (int i = 0; i <= maxHour; i++) {
		if (time[i].empty())
			continue;
		
		for (size_t j = 0; j < time[i].size(); j++) {
			if (time[i][j].first == time[i][j].second) {
				count++;
				continue;
			}
			for (int start = time[i][j].first; start <= time[i][j].second; start++) {
				possible = true;
				if (table[start] == 1) {
					if (start == time[i][j].first || start == time[i][j].second)
						continue;
					possible = false;
					break;
				}
			}

			if (possible) {
				count++;
				for (int start = time[i][j].first; start <= time[i][j].second; start++) {
					table[start] = 1;
					
				}
			}
		}
	}
	cout << count << endl;
}