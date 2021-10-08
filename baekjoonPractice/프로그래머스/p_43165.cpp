https://programmers.co.kr/learn/courses/30/lessons/43165
#include <iostream>
#include <vector>
using namespace std;
int ans;

void dfs(int idx, int target, vector<int> v) {
    if (idx == v.size()) {
        if (target == 0)
            ans++;
        return;
    }

    dfs(idx + 1, target + v[idx], v);
    dfs(idx + 1, target - v[idx], v);
}

int solution(vector<int> numbers, int target) {
    dfs(0, target, numbers);
    return ans;
}