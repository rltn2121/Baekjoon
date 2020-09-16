#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>  > time;

// 회의 종료 시간이 빠른 순서대로 정리(끝나는시간이 같을 경우 시작 시간 빠른 순서)
bool compare(pair<int, int> &t1, pair<int, int> &t2) {
	return (t1.second == t2.second ? t1.first < t2.first : t1.second < t2.second);
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a, b;
	
	for (int i = 0; i<n; i++) {
		cin >> a >> b;
		time.push_back(make_pair(a, b));
	}

	sort(time.begin(), time.end(),compare);

	int count = 0;
	int end = time[0].second;
	for (size_t i = 0; i < time.size(); i++) {
		if (time[i].first < end && count != 0)
			continue;

		if (time[i].first == time[i].second) {
			count++;
			continue;
		}
		end = time[i].second;
		count++;
	}
	cout << count << endl;
}