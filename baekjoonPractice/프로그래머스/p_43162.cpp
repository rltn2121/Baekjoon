https://programmers.co.kr/learn/courses/30/lessons/43162
#include <string>
#include <vector>

using namespace std;
bool visited[201];

void dfs(int now, vector<vector<int>> v) {
    if (visited[now]) return;
    visited[now] = 1;

    for (int i = 0; i < v[now].size(); i++) {
        if (v[now][i] == 1)
            dfs(i, v);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}