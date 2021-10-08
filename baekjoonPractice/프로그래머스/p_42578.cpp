// https://programmers.co.kr/learn/courses/30/lessons/42578
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<string> > v;
vector<string> cloth_list;
int arr[31], ans = 1, temp = 1, total_cnt;
void func(int index, int cnt, int total) {
	if (cnt == total) {
		ans += temp;
		return;
	}
	for (int i = index; i < cloth_list.size(); i++) {
		temp *= v[i].size();
		func(i + 1, cnt + 1, total);
		temp /= v[i].size();
	}
}

int solution(vector<vector<string>> clothes) {
	v.resize(31);
	for (vector<string> vec : clothes) {
		string name = vec[0];
		string cloth = vec[1];
		bool exist = false;
		for (int i = 0; i < cloth_list.size(); i++) {
			if (cloth_list[i] == cloth) {
				v[i].push_back(name);
				exist = 1;
				break;
			}
		}
		if (!exist) {
			cloth_list.push_back(cloth);
			v[cloth_list.size() - 1].push_back(name);
		}
	}

	// cout << cloth_list.size();
	// for (int i = 1; i <= cloth_list.size(); i++) {
	// 	func(0,0, i);
	// }
	for (int i = 0; i < cloth_list.size(); i++)
		ans *= (v[i].size() + 1);
	return ans - 1;
}