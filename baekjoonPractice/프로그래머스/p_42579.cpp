https://programmers.co.kr/learn/courses/30/lessons/42579
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define pis pair<int, string>
#define piii pair<int, pair<int, int> >
using namespace std;
map<string, int> m;
priority_queue<pis> map_pq;
struct Node {
    int genreRank;
    int playCnt;
    int id;
};
bool cmp(Node a, Node b) {
    if (a.genreRank == b.genreRank) {
        if (a.playCnt == b.playCnt) {
            return a.id < b.id;
        }
        else return a.playCnt > b.playCnt;
    }
    else return a.genreRank < b.genreRank;
}

vector<Node> v;
int genreCnt[10001];
vector<int> solution(vector<string> genres, vector<int> plays) {
    // 1. 맵<장르, 횟수>
    rep(i, genres.size())
        m[genres[i]] += plays[i];

    // 2. 장르별 재생횟수 큰 순으로 정렬
    for (auto it = m.begin(); it != m.end(); it++)
        map_pq.push({ it->second, it->first });

    // 3. 장르별 재생횟수를 장르 순위로 변환
    int idx = 0;
    while (!map_pq.empty()) {
        pis now = map_pq.top(); map_pq.pop();
        m[now.second] = idx++;
    }
    // 4.
    rep(i, genres.size()) {
        Node node;
        node.genreRank = m[genres[i]];
        node.playCnt = plays[i];
        node.id = i;
        v.push_back(node);
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> answer;
    idx = 0;
    for (Node node : v) {
        if (genreCnt[node.genreRank]++ < 2) {
            answer.push_back(node.id);
        }
    }
    return answer;
}