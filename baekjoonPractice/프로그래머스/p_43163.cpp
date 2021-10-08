// https://programmers.co.kr/learn/courses/30/lessons/43163
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v;
bool visited[100];
int ans = 10e9;

bool canGo(string, string);
int getTargetIndex(vector<string>, string);
void stringToInt(vector<string>);

void dfs(int now, int cnt, int target_idx) {
    if (now == target_idx)
        ans = min(ans, cnt);

    for (int i = 0; i < v[now].size(); i++) {
        if (visited[now]) continue;
        visited[now] = 1;
        dfs(v[now][i], cnt + 1, target_idx);
        visited[now] = 0;
    }
}

int solution(string begin, string target, vector<string> words) {
    // vector �ʱ�ȭ
    words.push_back(begin);
    v.resize(words.size());

    // target�� �ε��� ã��
    int target_idx = getTargetIndex(words, target);

    // ���� ���ڰ� ���� ���
    if (target_idx == -1) return 0;

    // �ܾ ���ڷ� ��ȯ
    stringToInt(words);

    // begin���� �ٲ� �� �ִ� �ܾ ���� ���
    if (words[words.size() - 1].size() == 0)
        return 0;

    cout << "��ȯ����";
    dfs(words.size() - 1, 0, target_idx);

    return ans;
}

bool canGo(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) cnt++;
        if (cnt > 1) return false;
    }
    return true;
}
int getTargetIndex(vector<string> words, string target) {
    int target_idx = -1;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == target) {
            target_idx = i;
            break;
        }
    }
    return target_idx;
}
void stringToInt(vector<string> words) {
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (canGo(words[i], words[j])) {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
}