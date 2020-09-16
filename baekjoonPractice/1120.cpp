#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<char> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	v.reserve(50);
	string a, b;
	cin >> a >> b;

	for (char c : a)
		v.push_back(c);
	
	int minIdx = 0;											// A를 몇칸 옮겨야 할 지
	int minDiff = 99999;									// A,B 차이의 최소값
	int shift = 0;											// 이동한 횟수
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int diff = 0;
		for (int j = shift; j < v.size(); j++) {
			if (b[j] != v[j])								// 다르면 더하기
				diff++;
		}
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i;
		}
		v.insert(v.begin(), '0');							// 문자열 A의 앞에 0을 추가해서 오른쪽으로 한칸 이동
		shift++;
	}
	v.clear();
	for (char c : a)
		v.push_back(c);

	// 문자열 A의 앞에 추가
	for (int i = minIdx - 1; i >= 0; i--) 
		v.insert(v.begin(),b[i]);

	// 문자열 A의 뒤에 추가
	for (int i = v.size(); i < b.length(); i++)
		v.push_back(b[i]);

	// A, B의 차이 계산
	int cnt = 0;
	for (int i = 0; i < b.length(); i++) {
		if (v[i] != b[i])
			cnt++;
	}
	cout << cnt << endl;
}