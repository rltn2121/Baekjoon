#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> p) {
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size() - 1;i++) {
        string now = p[i];
        string next = p[i + 1];
        if (now.length() <= next.length()) {
            int j = 0;
            for (j = 0; j < now.length();j++) {
                if (now[j] != next[j]) break;
            }
            if (j == now.length()) return false;
        }
    }
    return true;
}