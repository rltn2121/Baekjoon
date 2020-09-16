#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Person {
public:
	string name;
	int kor;
	int eng;
	int mat;
};
bool cmp(const Person& p1, const Person& p2) {
	if (p1.kor == p2.kor) {
		if (p1.eng == p2.eng) {
			if (p1.mat == p2.mat)
				return p1.name < p2.name;
			return p1.mat > p2.mat;
		}
		return p1.eng < p2.eng;
	}
	else
		return p1.kor > p2.kor;
}
vector<Person> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		Person p;
		cin >> p.name >> p.kor >> p.eng >> p.mat;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto it : v)
		cout << it.name << '\n';
}