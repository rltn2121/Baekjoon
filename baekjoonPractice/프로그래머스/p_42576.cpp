#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> p, vector<string> c) {
    sort(p.begin(), p.end());
    sort(c.begin(), c.end());
    for (int i = 0; i < p.size();i++) {
        if (p[i] != c[i]) {
            return p[i];
        }
    }
}