#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <math.h>
#define pii pair<int, int>
using namespace std;
deque<char> str[10];
long long weight[26];
int score[26];
vector<pii> v;
bool cmp(pii& a, pii& b) {
	return a.second > b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int max_len = -1;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (char c : input)
			str[i].push_back(c);
		max_len = max(max_len, (int)str[i].size());
	}

	// 1. 자릿수 맞추기
	for (int i = 0; i < n; i++) {
		int len = str[i].size();
		for (int j = 0; j < max_len - len; j++)
			str[i].push_front(' ');
	}

	// 2. 알파벳별 가중치 계산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < max_len; j++) {						// 반례
			char c = str[i][j];									// ABAB
			if (c >= 'A' && c <= 'Z')							// BABA
	//			weight[c - 'A'] += (1 << (max_len - j));		// CCCA
				weight[c - 'A'] += pow(10, (max_len - j));		// CCBA
		}
	}

	// 3. 가중치 -> 점수 환산
	for (int i = 0; i < 26; i++) {
		if (weight[i] == 0) continue;
		v.push_back({ i, weight[i] });
	}
	sort(v.begin(), v.end(), cmp);

	int tmp = 9;
	for (int i = 0; i < v.size(); i++)
		score[v[i].first] = tmp--;

	// 4. 계산
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long sum = 0;
		for (int j = 0; j < max_len; j++) {
			if (str[i][j] == ' ') continue;
			sum = sum * 10 + score[str[i][j] - 'A'];
		}
		ans += sum;
	}
	cout << ans;
}