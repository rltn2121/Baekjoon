#include <iostream>
#include <cstring>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, rec;
int rec_cnt[101];		// 추천횟수 저장
int rec_time[101];		// 추천시간 저장
int frame_num[101];		// 틀 번호 저장
int frame[21];			// 학생번호 저장
int getFrameNum() {
	// 빈 프레임 있으면 return
	rep(i, n){
		if (frame[i] == -1)
			return i;
	}
	
	int ret = -1;
	int min_rec = 987654321;
	int old_rec = 987654321;

	// 빈 프레임 없으면 비우기
	rep(i, n) {
		int now = frame[i];
		int temp_rec_cnt = rec_cnt[now];
		int temp_rec_time = rec_time[now];

		if (temp_rec_cnt < min_rec) {
			min_rec = rec_cnt[now];
			old_rec = rec_time[now];
			ret = i;
		}
		else if (temp_rec_cnt == min_rec && temp_rec_time < old_rec) {
			min_rec = rec_cnt[now];
			old_rec = rec_time[now];
			ret = i;
		}
	}

	
	return ret;
}
void init() {
	memset(rec_cnt, 0, sizeof(rec_cnt)+1);
	memset(rec_time, -1, sizeof(rec_cnt)+1);
	memset(frame_num, -1, sizeof(frame_num)+1);
	memset(frame, -1, sizeof(frame)+1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	cin >> n >> rec;
	rep(i,rec){
		int now;
		cin >> now;

		// now가 이미 존재하면 -> 추천수만 증가
		if (frame_num[now] != -1) {
			rec_cnt[now]++;
			continue;
		}

		// now가 존재하지 않으면 -> 신규 등록
		int pos = getFrameNum();

		// 해당 frame에 사람이 있으면
		if (frame[pos] != -1) {
			int del_student = frame[pos];
			rec_cnt[del_student] = 0;
			frame_num[del_student] = -1;
		}

		rec_cnt[now] = 1;
		rec_time[now] = i;
		frame[pos] = now;
		frame_num[now] = pos;
	}

	rep(i, 100) {
		if (frame_num[i] != -1)
			cout << i << '\n';
	}
}