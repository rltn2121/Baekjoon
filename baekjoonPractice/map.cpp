#include <iostream>
#include <map>
using namespace std;
int main() {
	map<int, double, less<int> > pairs;

	pairs.insert(make_pair(15, 2.7));
	pairs.insert(make_pair(30, 111.11));
	pairs.insert(make_pair(5, 1010.1));
	pairs.insert(make_pair(10, 22.22));
	pairs.insert(make_pair(25, 33.333));
	pairs.insert(make_pair(20, 9.345));
	pairs.insert(make_pair(5, 77.54));
	pairs.insert(make_pair(15, 77.54));

	cout << "pairs contains:\nKey\tValue\n";

	// first: Ű, second: value
	for (auto i : pairs)
		cout << i.first << '\t' << i.second << '\n';


	cout << pairs[5] << endl;
	cout << pairs[30] << endl;
	cout << pairs[1] << endl;

}