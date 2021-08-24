#include <iostream>
#include <cstring>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, rec;
int rec_cnt[101];		// ��õȽ�� ����
int rec_time[101];		// ��õ�ð� ����
int frame_num[101];		// Ʋ ��ȣ ����
int frame[21];			// �л���ȣ ����
int getFrameNum() {
	// �� ������ ������ return
	rep(i, n){
		if (frame[i] == -1)
			return i;
	}
	
	int ret = -1;
	int min_rec = 987654321;
	int old_rec = 987654321;

	// �� ������ ������ ����
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

		// now�� �̹� �����ϸ� -> ��õ���� ����
		if (frame_num[now] != -1) {
			rec_cnt[now]++;
			continue;
		}

		// now�� �������� ������ -> �ű� ���
		int pos = getFrameNum();

		// �ش� frame�� ����� ������
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