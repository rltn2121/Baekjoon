#include <iostream>
#include <vector>
using namespace std;

long sum(vector<int> &a) {
	int sum = 0;
	for (long n : a) {
		sum += n;
	}
	return sum;
}
