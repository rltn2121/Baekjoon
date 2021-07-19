#include <iostream>
#include <string>
#include <deque>
using namespace std;
deque<int> deq;
void initDeque(string arr_data) {
	int temp = 0;
	int idx = 1;
	while (idx < arr_data.length()-1) {
		temp = arr_data[idx]-'0';
		while (arr_data[idx+1]>='0' && arr_data[idx+1]<='9') {
			temp *= 10;
			temp+=arr_data[++idx] - '0';
		}
		deq.push_back(temp);
		temp = 0;
		idx += 2;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		deq.clear();
		string cmd;
		int n;

		cin >> cmd >> n;
		int cmd_cnt = cmd.length();

		string arr_data;
		cin >> arr_data;
		initDeque(arr_data);

		bool flag = true;
		bool direction = 1; // 1 -> front, 0 -> back
		for (int i = 0; i < cmd_cnt; i++) {
			if (cmd[i] == 'R') {
				direction = !direction;
			}

			else if (cmd[i] == 'D') {
				if(deq.empty()){
					flag = false;
					break;
				}
				if (direction)
					deq.pop_front();
				else
					deq.pop_back();
			}
		}
		if (flag) {
			cout << '[';
			int deq_size = deq.size();
			for (int i = 0; i < deq_size; i++) {
				if (direction) {
					cout << deq.front();
					deq.pop_front();
				}
				else {
					cout << deq[deq.size()-1];
					deq.pop_back();
				}
				if (i != deq_size - 1)
					cout << ',';
			}
			cout << "]\n";
		}
		else
			cout << "error\n";
	}
}